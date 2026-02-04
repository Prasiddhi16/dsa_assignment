#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 20
//to convert to postfix 
char stack [MAX];
int top=-1;
//stack ADT's
void push(char c)
{
    stack[++top]=c;
}
char pop() {
    return stack[top--];
}
char peek() {
    return stack[top];
}

//setting the operator precedence
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
//conversion main logic
void infixToPostfix(char* infix, char* postfix) {
    int i, k = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if (isdigit(c)) {
            postfix[k++] = c;  // operand goes directly to output
        } else if (c == '(') {
            push(c);//bracket conditiom
        } else if (c == ')') {
            while (top != -1 && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // remove '('
        } else { // operator pop on the basis of precedence
            while (top != -1 && precedence(peek()) >= precedence(c)) {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

//for evaluation of the postfix 
int evalStack[MAX];
int evalTop = -1;
//stack operations
void evalPush(int val) {
    evalStack[++evalTop] = val;
}
int evalPop() {
    return evalStack[evalTop--];
}
int evaluatePostfix(char* postfix) {
    int i;
    for (i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];
        if (isdigit(c)) {
            evalPush(c - '0'); // convert char to int
        } else {
            int val2 = evalPop();
            int val1 = evalPop();
            switch (c) {
                case '+': evalPush(val1 + val2); break;
                case '-': evalPush(val1 - val2); break;
                case '*': evalPush(val1 * val2); break;
                case '/': evalPush(val1 / val2); break;
            }
        }
    }
    return evalPop();
}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("Evaluation result: %d\n", result);

    return 0;
}



