%{
#include <stdio.h>
#include <stdlib.h>

int n, i, flag;
%}

%%
[0-9]+ {
    n = atoi(yytext);
    flag = 0;

    if(n <= 1)
        flag = 1;
    else
    {
        for(i = 2; i <= n/2; i++)
        {
            if(n % i == 0)
            {
                flag = 1;
                break;
            }
        }
    }

    if(flag == 0)
        printf("Number is Prime");
    else
        printf("Number is not Prime");
}
%%

int main()
{
    printf("Enter number:");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
