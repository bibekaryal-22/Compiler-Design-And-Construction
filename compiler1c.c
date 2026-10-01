#include <stdio.h>
#include <string.h>

int main()
{
    char a[100], b[10];

    do
    {
        printf("Enter the operator: ");
        fgets(a, sizeof(a), stdin);
        a[strcspn(a, "\n")] = '\0';

        if(strcmp(a, "+") == 0 || strcmp(a, "-") == 0 ||
           strcmp(a, "*") == 0 || strcmp(a, "/") == 0)
        {
            printf("It is an arithmetic operator.\n");
        }
        else if(strcmp(a, "==") == 0 || strcmp(a, ">") == 0 ||
                strcmp(a, "<") == 0 || strcmp(a, ">=") == 0 ||
                strcmp(a, "<=") == 0 || strcmp(a, "!=") == 0)
        {
            printf("It is a relational operator.\n");
        }
        else if(strcmp(a, "&&") == 0 || strcmp(a, "||") == 0 ||
                strcmp(a, "!") == 0)
        {
            printf("It is a logical operator.\n");
        }
        else if(strcmp(a, "=") == 0 || strcmp(a, "+=") == 0 ||
                strcmp(a, "-=") == 0)
        {
            printf("It is an assignment operator.\n");
        }
        else
        {
            printf("Invalid operator.\n");
        }

        printf("\nDo you want to continue (Y/N): ");
        fgets(b, sizeof(b), stdin);

    } while(b[0] == 'Y' || b[0] == 'y');

    return 0;
}