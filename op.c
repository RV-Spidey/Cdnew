#include <stdio.h>

int main()
{
    char ter[10], table[10][10], stack[20], input[20];
    char rel;
    int n, top = 0, i = 0, r, c, k;

    // 1. Read terminals and table
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

    // 2. Print the table
    printf("\nOPERATOR PRECEDENCE TABLE\n");
    for (c = 0; c < n; c++)
        printf("\t%c", ter[c]);
    for (r = 0; r < n; r++)
    {
        printf("\n%c", ter[r]);
        for (c = 0; c < n; c++)
            printf("\t%c", table[r][c]);
    }

    // 3. Read input
    printf("\n\nEnter input string ending with $: ");
    scanf("%s", input);

    stack[0] = '$';
    printf("\nSTACK\t\tINPUT\t\tACTION\n");

    // 4. Parse
    while (1)
    {
        // print stack
        for (k = 0; k <= top; k++)
            printf("%c", stack[k]);
        printf("\t\t");

        // print remaining input
        for (k = i; input[k] != '\0'; k++)
            printf("%c", input[k]);
        printf("\t\t");

        // accept?
        if (stack[top] == '$' && input[i] == '$')
        {
            printf("ACCEPT\n");
            break;
        }

        // find row (stack top) and column (input symbol)
        r = -1;
        c = -1;
        for (k = 0; k < n; k++)
        {
            if (ter[k] == stack[top])
                r = k;
            if (ter[k] == input[i])
                c = k;
        }
        if (r == -1 || c == -1)
        {
            printf("REJECT\n");
            break;
        }

        rel = table[r][c];

        if (rel == '<' || rel == '=')
        {
            // SHIFT: push relation, then symbol
            printf("SHIFT %c\n", input[i]);
            top++;
            stack[top] = rel;
            top++;
            stack[top] = input[i];
            i++;
        }
        else if (rel == '>')
        {
            // REDUCE: pop until '<', then pop '<'
            printf("REDUCE\n");
            while (stack[top] != '<')
                top--;
            top--;
        }
        else
        {
            printf("REJECT\n");
            break;
        }
    }
    return 0;
}
