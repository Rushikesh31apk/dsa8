#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 20

char stack[max];
char a[max];
char post[max];
int top = -1;

int isfull() {
    return (top == max - 1);
}

int isempty() {
    return (top == -1);
}

void push(char x) {
    if (isfull()) {
        printf("cannot insert stack full\n");
    } else {
        stack[++top] = x;
    }
}

char pop() {
    if (isempty()) {
        printf("stack empty");
        return '\0'; 
    } else {
        return stack[top--];
    }
}

int pre(char x) {
    if (x == '^') {
        return 3;
    } else if (x == '*' || x == '/') {
        return 2;
    } else if (x == '+' || x == '-') {
        return 1;
    } else {
        return 0;
    }
}

void postfix(char a[]) {
    int i, j = 0;
    char symbol, next;
    for (i = 0; i < strlen(a); i++) {
        symbol = a[i];
        switch (symbol) {
            case '(':
                push(symbol);
                break;
            case ')':
                while ((next = pop()) != '(') {
                    post[j++] = next;
                }
                break;
            case '+':
            case '-':
            case '/':
            case '*':
            case '^':
                while (!isempty() && pre(stack[top]) >= pre(symbol)) {
                    post[j++] = pop();
                }
                push(symbol);
                break;
            default:
                post[j++] = symbol;
        }
    }
    while (!isempty()) {
        post[j++] = pop();
    }
    post[j] = '\0';
}

void display(char b[]) {
    int i;
    for (i = 0; i < strlen(b); i++) {
        printf("%c", b[i]);
    }
}

int main() {
    printf("enter infix exp:");
    gets(a);
    postfix(a);
    display(post);

    return 0;
}

