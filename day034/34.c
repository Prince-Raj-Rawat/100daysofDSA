#include <stdio.h>
#include <ctype.h>
#define MAX 100
int top = -1;
char stack[MAX];

int isfull(){
    return top == MAX-1;
}

int isempty(){
    return top == -1;
}

void push(char c){
    if(isfull()){
        printf("\nstack is full.");
        return ;
    }
    stack[++top]=c;
}

char pop(){
    if(isempty()){
        printf("\nthe stack is empty");
        return -1;
    }
    return stack[top--];
}

int precedence(char c){
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

void intopost(char *infix){
    char postfix[MAX];
    int k = 0;
    for (int i = 0; infix[i] ; i++){
        char c = infix[i];
        if(isalnum(c)){
            postfix[k++]=c;
        }
        else if(c == '(') push(c);
        else if(c == ')'){
            while(!isempty() && peek() != '('){
                postfix[k++]=pop();
            }
            if(!isempty()){
                pop();
            }
        }
        else{
            while(!isempty && precedence(peek())>=precedence(c)){
                postfix[k++]=pop();
                
            }
            push(c);
        }
        
    }
    while(!isempty()){
        postfix[k++]=pop();
    }
    scanf("%s",postfix);
    return ;
}

void evalutation(char *postfix){

}