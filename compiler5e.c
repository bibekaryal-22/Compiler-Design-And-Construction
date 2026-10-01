#include <stdio.h>
int main()
{
    char result, op1, op2, operator;
    printf("Enter intermediate code: ");
    scanf(" %c = %c %c %c", &result, &op1, &operator, &op2);
    printf("\nTarget code:\n");
    printf("MOV R0, %c\n", op1);
    if (operator == '+')
        printf("ADD R0, %c\n", op2);
    else if (operator == '-')
        printf("SUB R0, %c\n", op2);
    else if (operator == '*')
        printf("MUL R0, %c\n", op2);
    else if (operator == '/')
        printf("DIV R0, %c\n", op2);
    printf("MOV %c, R0\n", result);
    return 0;
}