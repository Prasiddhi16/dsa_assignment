#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20
int top=-1;
char stack[MAX];

void push(char ch)
{
    if(top==MAX-1)
    {
        printf("The stack is overflown\n");
        return ;
    }
    stack[++top]=ch;
    return ;
}
char pop()
{
    if(top==-1)
    {
        printf("The stack is empty\n");
        return '\0';
    }
    char ch=stack[top--];
    return ch;
}
int balance(char *exp)
{
    top = -1;
    int i;
    for(i=0;i<strlen(exp);i++)
    {
        char ch=exp[i];
        if(ch=='['||ch=='{'||ch=='(')
        {
            push (ch);
        }
        else if(ch==']'||ch=='}'||ch==')')
        {
            char popvalue= pop();
            if ((ch == ')' && popvalue != '(') ||(ch == ']' && popvalue != '[') ||(ch == '}' && popvalue != '{')) 
            {
                return 0;
        }
    }
}
    return (top==-1);

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
        if(balance(exp[i]))
        {
            printf("The expression is balanced\n");

        }
        else{
            printf("The expression isn't balanced\n");
        }
    }
return 0;
}