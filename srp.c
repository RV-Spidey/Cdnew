#include <stdio.h>
#include <string.h>

char input[20], stack[20];
int top = -1;   // position of top of stack
int i = 0;      // position of next input symbol
int len;        // length of input

// prints the stack and the remaining input
void display()
{
    int k;
    printf("\n$");
    for (k = 0; k <= top; k++)
        printf("%c", stack[k]);

    printf("\t\t");
    for (k = i; k < len; k++)
        printf("%c", input[k]);
    printf("$\t\t");
}

void reduce()
{
    // Rule 1: a -> E  or  b -> E
    if (stack[top] == 'a' || stack[top] == 'b')
    {
        char c = stack[top];
        stack[top] = 'E';
        display();
        printf("REDUCE E->%c", c);
    }

    // Rule 2: E+E -> E,  E*E -> E,  E/E -> E
    if (top >= 2 && stack[top] == 'E' && stack[top-2] == 'E')
    {
        char op = stack[top-1];
        if (op == '+' || op == '*' || op == '/')
        {
            top = top - 2;
            display();
            printf("REDUCE E->E%cE", op);
        }
    }
}

int main()
{
    printf("GRAMMAR\n E->E+E\n E->E*E\n E->E/E\n E->a|b\n");
    printf("\nEnter input: ");
    scanf("%s", input);
    len = strlen(input);

    printf("\nSTACK\t\tINPUT\t\tACTION");
    display();
    printf("--");

    while (i < len)
    {
        // SHIFT
        top++;
        stack[top] = input[i];
        i++;
        display();
        printf("SHIFT %c", stack[top]);

        // REDUCE
        reduce();
    }

    display();
    if (top == 0 && stack[0] == 'E')
        printf("ACCEPT\n");
    else
        printf("REJECT\n");

    return 0;
}
