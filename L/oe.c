%{
#include <stdio.h>
#include <stdlib.h>
int a;
%}

%%
[0-9]+  {
            a = atoi(yytext);
            if (a % 2 == 0)
                printf("even\n");
            else
                printf("odd\n");
        }
%%

int main()
{
    printf("enter the number:");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
