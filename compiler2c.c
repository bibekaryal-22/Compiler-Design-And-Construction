// 3. Wap to recognize string under a*, a*b+ and abb.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

enum states {q0, q1, qd};
enum states delta(enum states, char);

int main() {
    char input[100];
    enum states curr_state = q0;
    int i = 0;

    printf("\nEnter a string: ");
    if (fgets(input, sizeof(input), stdin) != NULL) {

    input[strcspn(input, "\n")] = '\0';
    }
    char ch = input[i];

    while (ch != '\0') {
        curr_state = delta(curr_state, ch);
        ch = input[++i];
    }

    if (curr_state == q0 || curr_state == q1) {
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
            if(ch == 'a') {
                curr_state = q0;
            }
            else if (ch == 'b') {
                return q1;
            }
            else {
                curr_state = q1;
            }
            break;
        case q1:
            if(ch == 'b') {
                curr_state = q1;
            }
            else {
                curr_state = qd;
            }
            break;
        case qd:
            if (ch == 'a' || ch == 'b') {
                curr_state = qd;
            }
            break;
        default:
        printf("Invalid state");
        break;
    }
    return curr_state;
}