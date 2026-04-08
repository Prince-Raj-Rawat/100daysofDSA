#include <stdio.h>
#include <ctype.h>

#define MAX 100
int top =-1;
char stack[MAX];

void push(char ch){
    stack[++top]=ch;
}
char pop(){
    return stack[top--];
}

char peek(){
    return stack[top];
}

int isempty(){
    return top == -1;
}

int precedence(char op){
    if(op == '+' || op == '-') return 1;
    if(op == '*' || op == '/') return 2;
    if(op == '^' ) return 3;
    return 0;
}

void infixtopostfix(char *infix){
    char postfix[MAX];
    int k = 0;
    for(int i = 0; infix[i]; i++){
        char c = infix[i];
        if(isalnum(c)){
            postfix[k++]=c;
        }
        else if(c=='(') push(c);
        else if(c==')'){
            while(!isempty() && peek()!= '('){
                postfix[k++]=pop();
            }
            if(!isempty()){
                pop();
            }
        }
        else{
            while(!isempty()&& precedence(peek())>= precedence(c)){
            postfix[k++]=pop();
        }
        push(c);
    }
    while(!isempty()){
        postfix[k++]=pop();
    }
    postfix[k] = '\0';
    printf("%s\n", postfix);
    
}
}

int main() {
    char infix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    printf("Postfix expression: ");
    infixtopostfix(infix);

    return 0;
}


