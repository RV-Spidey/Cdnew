#include <stdio.h>
#include <string.h>

char expr[20];
char temp[] = {'z','y','x','w','v','u','t'};
int count = 0;

// returns position of first op1 or op2, or -1 if not found
int find(char op1, char op2)
{
    int i;
    for (i = 0; expr[i] != '\0'; i++)
    {
        if (expr[i] == op1 || expr[i] == op2)
            return i;
    }
    return -1;
}

// prints  t = a op b  and replaces "a op b" with t in expr
void generate(int pos)
{
    int k, len;
    char t = temp[count];
    count++;

    printf("%c = %c %c %c\n", t, expr[pos-1], expr[pos], expr[pos+1]);

    expr[pos-1] = t;            // temp takes the place of the left operand
    len = strlen(expr);
    for (k = pos; k < len - 2; k++)
        expr[k] = expr[k+2];    // shift the rest 2 places left
    expr[len-2] = '\0';
}

int main()
{
    int pos;
    printf("Enter expression: ");
    scanf("%s", expr);
    printf("\nThree Address Code:\n");

    // Step 1: * and / first (higher precedence)
    pos = find('*', '/');
    while (pos != -1)
    {
        generate(pos);
        pos = find('*', '/');
    }

    // Step 2: then + and -
    pos = find('+', '-');
    while (pos != -1)
    {
        generate(pos);
        pos = find('+', '-');
    }

    return 0;
}
