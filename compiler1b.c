#include <stdio.h>
#include <string.h>

int main()
{
    char str[100], choice[10];
    int i, isValid;

    char keywords[][10] = {
        "auto", "break", "case", "char", "const", "continue", "default", "do",
        "double", "else", "enum", "extern", "float", "for", "goto", "if",
        "int", "long", "register", "return", "short", "signed", "sizeof", "static",
        "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };

    do
    {
        printf("Enter an identifier: ");
        fgets(str, sizeof(str), stdin);

        int len = 0;
        while (str[len] != '\0' && str[len] != '\n') {
            len++;
        }
        str[len] = '\0';

        isValid = 1;

        if (len == 0) {
            isValid = 0;
        }

        else if (!((str[0] >= 'a' && str[0] <= 'z') || 
                   (str[0] >= 'A' && str[0] <= 'Z') || 
                   str[0] == '_')) {
            isValid = 0;
        }

        else {
            for (i = 1; i < len; i++) {
                if (!((str[i] >= 'a' && str[i] <= 'z') || 
                      (str[i] >= 'A' && str[i] <= 'Z') || 
                      (str[i] >= '0' && str[i] <= '9') || 
                      str[i] == '_')) {
                    isValid = 0;
                    break;
                }
            }
        }

        if (isValid) {
            for (i = 0; i < 32; i++) {
                if (strcmp(str, keywords[i]) == 0) {
                    isValid = 0;
                    printf("Result: NOT a valid identifier (It is a reserved keyword).\n");
                    break;
                }
            }
        }

        if (isValid) {
            printf("Result: IS a valid identifier.\n");
        } 
        else if (len > 0 && !(str[0] >= 'a' && str[0] <= 'z') && !(str[0] >= 'A' && str[0] <= 'Z') && str[0] != '_') {
            printf("Result: NOT a valid identifier (Cannot start with digits or special characters).\n");
        }
        else
        {
            printf("Invalid.......");
        }
        printf("\nCONTINUE??? Y/N: ");
        fgets(choice, sizeof(choice), stdin);

    } while (choice[0] == 'Y' || choice[0] == 'y');

    return 0;
}