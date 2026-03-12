
#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    return stack[top--];
}

int precedence(char x)
{
    if(x=='+' || x=='-')
        return 1;
    if(x=='*' || x=='/')
        return 2;
    if(x=='^')
        return 3;
    return 0;
}

int main()
{
    char exp[100];
    int i=0;

    scanf("%s",exp);

    while(exp[i] != '\0')
    {
        if(isalnum(exp[i]))
        {
            printf("%c",exp[i]);
        }
        else
        {
            while(top!=-1 && precedence(stack[top]) >= precedence(exp[i]))
            {
                printf("%c",pop());
            }
            push(exp[i]);
        }
        i++;
    }

    while(top!=-1)
    {
        printf("%c",pop());
    }

    return 0;
}