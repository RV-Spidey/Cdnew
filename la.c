#include <stdio.h>
#include <ctype.h>
#include <string.h>

char keywords[][20] = {
    "int", "float", "char", "double", "if", "else", "while",
    "for", "return", "void", "break", "continue", "switch",
    "case", "default", "do", "struct", "long", "short"
};

int isKeyword(char str[]) {
    int n = sizeof(keywords) / sizeof(keywords[0]);
    for (int i = 0; i < n; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[100];
    int i;

    fp = fopen("input.c", "r");

    if (fp == NULL) {
        printf("Cannot open file!\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {

        // Ignore spaces, tabs and newlines
        if (isspace(ch))
            continue;

        // Ignore comments
        if (ch == '/') {
            char next = fgetc(fp);

            // Single-line comment
            if (next == '/') {
                while ((ch = fgetc(fp)) != '\n' && ch != EOF);
            }

            // Multi-line comment
            else if (next == '*') {
                while ((ch = fgetc(fp)) != EOF) {
                    if (ch == '*') {
                        if ((ch = fgetc(fp)) == '/')
                            break;
                        else
                            ungetc(ch, fp);
                    }
                }
            }

            // Division operator
            else {
                printf("Operator : /\n");
                ungetc(next, fp);
            }
        }

        // Identifier or Keyword
        else if (isalpha(ch) || ch == '_') {
            i = 0;
            buffer[i++] = ch;

            while ((ch = fgetc(fp)) != EOF &&
                   (isalnum(ch) || ch == '_')) {
                buffer[i++] = ch;
            }

            buffer[i] = '\0';

            if (isKeyword(buffer))
                printf("Keyword : %s\n", buffer);
            else
                printf("Identifier : %s\n", buffer);

            if (ch != EOF)
                ungetc(ch, fp);
        }

        // Number
        else if (isdigit(ch)) {
            i = 0;
            buffer[i++] = ch;

            while ((ch = fgetc(fp)) != EOF &&
                   isdigit(ch)) {
                buffer[i++] = ch;
            }

            buffer[i] = '\0';
            printf("Number : %s\n", buffer);

            if (ch != EOF)
                ungetc(ch, fp);
        }

        // Operators
        else if (strchr("+-*=<>!%", ch)) {
            printf("Operator : %c\n", ch);
        }

        // Special Symbols
        else if (strchr("(){}[],;.#", ch)) {
            printf("Special Symbol : %c\n", ch);
        }
    }

    fclose(fp);
    return 0;
}
