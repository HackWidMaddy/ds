#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    char *arr;
    int top;
    int size;
};

void init(struct Stack *s1) {
    s1->size = 10;
    s1->arr = (char *)malloc(sizeof(char) * s1->size);
    s1->top = -1;
}

int isOperator(char data) {
    return (data == '+' || data == '-' || data == '*' || data == '/' || data == '^' || data == '(' || data == ')');
}

int isEmpty(struct Stack *s1) {
    return s1->top == -1;
}

int precedence(char data) {
    if (data == '^') return 3;
    if (data == '*' || data == '/') return 2;
    if (data == '+' || data == '-') return 1;
    return 0; // Parentheses are handled separately
}

char peek(struct Stack *s1) {
    return s1->arr[s1->top];
}

char pop(struct Stack *s1) {
    return s1->arr[s1->top--];
}

void push(struct Stack *s1, char data) {
    s1->arr[++s1->top] = data;
}

int main() {
    struct Stack *s1 = (struct Stack *)malloc(sizeof(struct Stack));
    init(s1);

    char expression[] = "(A+B^C)*D+E^5";
    int len = strlen(expression);
    char secondarray[len + 1];
    int secondarraycounter = 0;

    // Reverse the expression
    for (int i = len - 1; i >= 0; i--) {
        if (expression[i] == '(')
            secondarray[secondarraycounter++] = ')';
        else if (expression[i] == ')')
            secondarray[secondarraycounter++] = '(';
        else
            secondarray[secondarraycounter++] = expression[i];
    }
    secondarray[secondarraycounter] = '\0';

    // Process the reversed expression
    for (int i = 0; secondarray[i] != '\0'; i++) {
        if (!isOperator(secondarray[i])) {
            printf("%c", secondarray[i]);
        } else {
            if (secondarray[i] == '(') {
                push(s1, secondarray[i]);
            } else if (secondarray[i] == ')') {
                while (!isEmpty(s1) && peek(s1) != '(') {
                    printf("%c", pop(s1));
                }
                pop(s1); // Pop '('
            } else {
                while (!isEmpty(s1) && precedence(secondarray[i]) <= precedence(peek(s1))) {
                    printf("%c", pop(s1));
                }
                push(s1, secondarray[i]);
            }
        }
    }

    // Pop remaining operators
    while (!isEmpty(s1)) {
        printf("%c", pop(s1));
    }

    free(s1);
    return 0;
}
