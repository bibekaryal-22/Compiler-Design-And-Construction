// RE, Finite automata and depvelopment of lexical analyzer
// 1) Write a c program to implement the dfa for accepting all strings that end with 00 over an alphabet {0,1}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum states {q0, q1, qf};
enum states delta(enum states, char);

int main() {
    char input[100];
    enum states curr_state = q0;
    int i = 0;

    printf("\nEnter a binary string: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {
            input[strcspn(input, "\n")] = '\0';
    }
    char ch = input[i];

    while (ch != '\0') {
        curr_state = delta(curr_state, ch);
        ch = input[++i];
    }

    if (curr_state == qf) {
        printf("\nThe string is Accepted\n");
    } else {
        printf("\nThe string is Rejected\n");
    }

    return 0;
}

enum states delta(enum states s, char ch) {
    enum states curr_state;

    switch (s) {
        case q0:
            if(ch == '1') {
                curr_state = q0;
            }
            else {
                curr_state = q1;
                
            }
            break;
        case q1:
            if(ch == '1') {
                curr_state = q0;
            }
            else {
                curr_state = qf;
            }
            break;
        case qf:
            if(ch == '0') {

                curr_state = qf;
            }
            else {
                curr_state = q0;
            }
            break;
        default:
            printf("No more states");
            break;
    }
    return curr_state;
}