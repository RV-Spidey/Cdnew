#include <stdio.h>
#include <string.h>

char ter[10];          // terminals, e.g. i+*$
char table[10][10];    // precedence relations: < > = or e (error)
char stack[20], input[20];
int n, top = 0, i = 0;

// returns position of terminal c in ter[], or -1 if not found
int pos(char c)
{
    int k;
    for (k = 0; k < n; k++)
    {
        if (ter[k] == c)
            return k;
    }
    return -1;
}

// prints the stack and the remaining input
void display()
{
    int k;
    printf("\n");
    for (k = 0; k <= top; k++)
        printf("%c", stack[k]);

    printf("\t\t");
    for (k = i; input[k] != '\0'; k++)
        printf("%c", input[k]);
    printf("\t\t");
}

int main()
{
    int r, c;
    char rel;

    printf("Enter number of terminals: ");
    scanf("%d", &n);
    printf("Enter the terminals: ");
    scanf("%s", ter);

    printf("Enter table values (<, >, = or e for error):\n");
    for (r = 0; r < n; r++)
    {
        for (c = 0; c < n; c++)
        {
            printf("%c %c : ", ter[r], ter[c]);
            scanf(" %c", &table[r][c]);   // space before %c skips the Enter key
        }
    }

    // print the table
    printf("\nOPERATOR PRECEDENCE TABLE\n");
    for (c = 0; c < n; c++)
        printf("\t%c", ter[c]);
    for (r = 0; r < n; r++)
    {
        printf("\n%c", ter[r]);
        for (c = 0; c < n; c++)
            printf("\t%c", table[r][c]);
    }

    printf("\n\nEnter input string ending with $: ");
    scanf("%s", input);

    stack[0] = '$';
    printf("\nSTACK\t\tINPUT\t\tACTION");
    display();

    while (1)
    {
        if (stack[top] == '$' && input[i] == '$')
        {
            printf("ACCEPT");
            break;
        }

        r = pos(stack[top]);   // row = top of stack
        c = pos(input[i]);     // column = current input
        if (r == -1 || c == -1)
        {
            printf("REJECT");
            break;
        }
        rel = table[r][c];

        if (rel == '<' || rel == '=')
        {
            // SHIFT: push the relation, then the symbol
            printf("SHIFT %c", input[i]);
            top++;
            stack[top] = rel;
            top++;
            stack[top] = input[i];
            i++;
        }
        else if (rel == '>')
        {
            // REDUCE: pop until '<', then pop the '<' too
            while (stack[top] != '<')
                top--;
            top--;
            printf("REDUCE");
        }
        else
        {
            printf("REJECT");
            break;
        }

        display();
    }
    printf("\n");
    return 0;
}
