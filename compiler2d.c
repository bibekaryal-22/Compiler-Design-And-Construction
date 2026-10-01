//4. Wap to implement design of lexical analyzer to recognize token(identifier, keyword, operator, constant and special symbol etc)

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char buf[]) {
    if (strcmp(buf, "int") == 0 || strcmp(buf, "float") == 0 || 
        strcmp(buf, "char") == 0 || strcmp(buf, "if") == 0 || 
        strcmp(buf, "else") == 0 || strcmp(buf, "while") == 0) {
        return 1;
    }
    return 0;
}

int main() {
    char user_input[200];
    FILE *fp;

    // 1. Get input at runtime and write it to input.txt
    printf("Enter code snippet: ");
    fgets(user_input, sizeof(user_input), stdin);

    fp = fopen("input.txt", "w");
    if (fp == NULL) return 1;
    fputs(user_input, fp);
    fclose(fp);

    // 2. Arrays to store grouped outputs
    char keywords[100] = "", identifiers[100] = "", constants[100] = "";
    char operators[100] = "", symbols[100] = "";

    // 3. Open input.txt for reading
    fp = fopen("input.txt", "r");
    if (fp == NULL) return 1;

    char ch, buf[20];
    int i;

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == ' ' || ch == '\t' || ch == '\n') continue;

        switch (ch) {
            case '+': case '-': case '*': case '/': case '=':
                sprintf(operators + strlen(operators), "%c, ", ch);
                break;

            case ';': case ',': case '(': case ')': case '{': case '}':
                sprintf(symbols + strlen(symbols), "%c, ", ch);
                break;

            default:
                if (isdigit(ch)) {
                    i = 0;
                    buf[i++] = ch;
                    while (isdigit(ch = fgetc(fp))) buf[i++] = ch;
                    buf[i] = '\0';
                    ungetc(ch, fp);
                    sprintf(constants + strlen(constants), "%s, ", buf);
                }
                else if (isalpha(ch)) {
                    i = 0;
                    buf[i++] = ch;
                    while (isalnum(ch = fgetc(fp))) buf[i++] = ch;
                    buf[i] = '\0';
                    ungetc(ch, fp);

                    if (isKeyword(buf)) {
                        sprintf(keywords + strlen(keywords), "%s, ", buf);
                    } else {
                        sprintf(identifiers + strlen(identifiers), "%s, ", buf);
                    }
                }
                break;
        }
    }
    fclose(fp);

    // 4. Print Grouped Output
    printf("\n--- LEXICAL ANALYSIS RESULT ---\n");
    printf("Keywords        : %s\n", strlen(keywords) ? keywords : "None");
    printf("Identifiers     : %s\n", strlen(identifiers) ? identifiers : "None");
    printf("Constants       : %s\n", strlen(constants) ? constants : "None");
    printf("Operators       : %s\n", strlen(operators) ? operators : "None");
    printf("Special Symbols : %s\n", strlen(symbols) ? symbols : "None");

    return 0;
}