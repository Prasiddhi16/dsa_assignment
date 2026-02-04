#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
int top=-1;//setting the stack as empty initially
char stack[MAX];//declaring the stack array

void push(char ch)
{
    if(top==MAX-1)
    {
        printf("The stack is overflown\n");
        return ;
    }
    stack[++top]=ch;//adding value at top after increasing  value of top
    return ;
}
char pop()
{
    if(top==-1)
    {
        printf("The stack is empty\n");
        return '\0';
    }
    char ch=stack[top--];//returning the top value and decreasing the value of top
    return ch;
}
int balance(char *exp)
{
    top = -1;
    int i;
    for(i=0;i<strlen(exp);i++)
    {
        char ch=exp[i];//each character acessed
        if(ch=='['||ch=='{'||ch=='(')//ignoring other characters and pushing starting brackets
        {
            push (ch);
        }
        else if(ch==']'||ch=='}'||ch==')')//checking for ending brackets 
        {
            char popvalue= pop();//poping the starting brackets
            if ((ch == ')' && popvalue != '(') ||(ch == ']' && popvalue != '[') ||(ch == '}' && popvalue != '{')) 
            {
                return 0;
        }
    }
}
    return (top==-1);//as stack is empty when balanced

}
int main()
{
    char *exp[]={ "a + (b - c) * (d",
        "m + [a - b * (c + d * {m)]",
        "a + (b - c)"
    };
    int n=sizeof(exp)/sizeof(exp[0]);
    for(int i=0;i<n;i++)
    {
        printf("Expressions: %s \n",exp[i]);
        if(balance(exp[i]))//passing the expressions
        {
            printf("The expression is balanced\n");

        }
        else{
            printf("The expression isn't balanced\n");
        }
    }
return 0;
}