#include <stdio.h>
#include <string.h>
#include <ctype.h>

int n, m = 0;
char a[10][10], f[20];

void follow(char c);
void first(char c);

int main()
{
    int i, z;
    char c;
    printf("Enter the no of productions:\n");
    scanf("%d", &n);
    printf("Enter the productions:\n");
    for (i = 0; i < n; i++)
        scanf("%s", a[i]);
    do
    {
        m = 0;
        f[0] = '\0';
        printf("Enter the elements whose first and follow is to be found:\n");
        scanf(" %c", &c);
        first(c);
        printf("First(%c)={%s}\n", c, f);

        m = 0;
        f[0] = '\0';
        follow(c);
        printf("Follow(%c)={%s}\n", c, f);

        printf("Continue(0/1)?\n");
        scanf("%d", &z);
    } while (z == 1);
    return 0;
}

void first(char c)
{
    int k;
    if (!isupper(c) && strchr(f, c) == NULL)
    {
        f[m++] = c;
        f[m] = '\0';
    }
    for (k = 0; k < n; k++)
    {
        if (a[k][0] == c)
        {
            if (a[k][2] == '$')
                follow(a[k][0]);
            else if (islower(a[k][2]))
            {
                if (strchr(f, a[k][2]) == NULL)
                {
                    f[m++] = a[k][2];
                    f[m] = '\0';
                }
            }
            else
                first(a[k][2]);
        }
    }
}

void follow(char c)
{
    int i, j;
    if (a[0][0] == c && strchr(f, '$') == NULL)
    {
        f[m++] = '$';
        f[m] = '\0';
    }
    for (i = 0; i < n; i++)
    {
        for (j = 2; j < strlen(a[i]); j++)
        {
            if (a[i][j] == c)
            {
                if (a[i][j + 1] != '\0')
                    first(a[i][j + 1]);
                if (a[i][j + 1] == '\0' && c != a[i][0])
                    follow(a[i][0]);
            }
        }
    }
}
