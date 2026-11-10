%{
#include <stdio.h>
#include <string.h>

int len, flag = 0;
%}

%%
[a-zA-Z0-9]+ {
    len = strlen(yytext);

    for(i = 0; i < len/2; i++)
    {
        if(yytext[i] != yytext[len-1-i])
        {
            flag = 1;
            break;
        }
    }

    if(flag == 0)
        printf("String is Palindrome");
    else
        printf("String is not Palindrome");

    flag = 0;
}
%%

int main()
{
    printf("Enter a string:");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
