// 2. Wap to implement dfa for accepting even number of 0's and even number of 1's.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum states {q0, q1, q2, q3};
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

    if (curr_state == q0) {
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
            if (ch == '0') {
                curr_state = q1;
            }
            else {
                curr_state = q3;
            }
            break;
        case q1:
            if (ch == '1') {
                curr_state = q2;
            }
            else {
                curr_state = q0;
            }
            break;
        case q2:
            if(ch == '0') {
                curr_state = q3;
            }
            else {
                curr_state = q1;
            }
            break;
        case q3:
            if(ch == '1') {
                curr_state = q0;
            }
            else {
                curr_state = q2;
            }
            break;
        default:
        printf("Invalid input!");
        break;
    }
    return curr_state;
}