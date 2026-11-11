#include <stdio.h>
#include <ctype.h>

int main()
{
    char prod[10][20];
    int n, i, j, k;
    char var, val;

    // 1. Read productions
    printf("Enter number of productions: ");
    scanf("%d", &n);
    printf("Enter %d productions:\n", n);
    for (i = 0; i < n; i++)
        scanf("%s", prod[i]);

    // 2. Propagate constants
    for (i = 0; i < n; i++)
    {
        // is this line like  a=5 ?
        if (isdigit(prod[i][2]) && prod[i][3] == '\0')
        {
            var = prod[i][0];   // the variable, e.g. a
            val = prod[i][2];   // its value,    e.g. 5

            for (j = i + 1; j < n; j++)
            {
                // replace var with val on the right side
                for (k = 2; prod[j][k] != '\0'; k++)
                {
                    if (prod[j][k] == var)
                        prod[j][k] = val;
                }
                // stop if var gets a new value on this line
                if (prod[j][0] == var)
                    break;
            }
        }
    }

    // 3. Print result
    printf("\nOptimized code:\n");
    for (i = 0; i < n; i++)
        printf("%s\n", prod[i]);

    return 0;
}
