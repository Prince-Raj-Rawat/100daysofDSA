#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

int top = -1;
char stack[MAX];

int isfull() {
    return top == MAX - 1;
}

int isempty() {
    return top == -1;
}

void push(char c) {
    if (isfull()) return;
    stack[++top] = c;
}

char pop() {
    if (isempty()) return -1;
    return stack[top--];
}

char peek() {
    if (isempty()) return -1;
    return stack[top];
}

int precedence(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

void intopost(char *infix, char *postfix) {
    int k = 0;
    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!isempty() && peek() != '(') {
                postfix[k++] = pop();
            }
            if (!isempty()) pop();
        } else {
            while (!isempty() && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while (!isempty()) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int evalpost(char *postfix) {
    int st[MAX], t = -1;
    for (int i = 0; postfix[i]; i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            st[++t] = c - '0';
        } else {
            int b = st[t--];
            int a = st[t--];
            switch (c) {
                case '+': st[++t] = a + b; break;
                case '-': st[++t] = a - b; break;
                case '*': st[++t] = a * b; break;
                case '/': st[++t] = a / b; break;
                case '^': {
                    int res = 1;
                    for (int j = 0; j < b; j++) res *= a;
                    st[++t] = res;
                    break;
                }
            }
        }
    }
    return st[t];
}

int main() {
    char infix[MAX], postfix[MAX];
    fgets(infix, sizeof(infix), stdin);
    infix[strcspn(infix, "\n")] = 0;
    intopost(infix, postfix);
    printf("Postfix: %s\n", postfix);
    int result = evalpost(postfix);
    printf("Result: %d\n", result);
    return 0;
}
