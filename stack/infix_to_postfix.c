#include <stdio.h>
#include <string.h>
#define MAX 50
//Array Declaration
char arr[MAX];
int t = -1; //t is the index of top element
//function definition
void push(char data);
char pop();
char top();
int isempty();
int isfull();
int size();
void infix_to_postfix(char input[]);
int prcd(char ch);
int isoperand(char ch); 

int main()
{
    infix_to_postfix("a+b*c");
    infix_to_postfix("(a+b)*c+(d-a)");
    infix_to_postfix("A-B/C-D*E+F");

    return(0);
}
//function definitions
void push(char data)
{
    if(t == MAX-1)
    {
        printf("Stack is Overflow\n");
        return;
    }
    arr[++t] = data;
}
char pop()
{
    if(t == -1)
    {
        printf("Stack is Underflow\n");
        return(t);
    }
    return(arr[t--]); 
}
char top()
{
    if(t == -1)
        return(t);
    return(arr[t]);
}
int size()
{
    return(t + 1);
}
int isempty()
{
    return(t == -1);
}
int isfull()
{
    return(t == MAX-1);
}
void infix_to_postfix(char input[])
{
    char ch;
    int i = 0;
    while(input[i] != '\0')
    {
        ch = input[i];
        if(isoperand(ch))
            printf("%c", ch);
        else if(ch == '(')
            push(ch);
        else if(ch == ')')
        {
            while(top() != '(' && !isempty())
                printf("%c", pop());
        }
        else
        {
            while(prcd(ch) <= prcd(top()) && top() != '(' && !isempty())
            {
                printf("%c", pop());
            }
            push(ch);
        }
        i++;
    }
    while(!isempty())
    {
        if(top() == '(')
            pop();
        else
         printf("%c", pop());   
    }
    printf("\n");
}
int prcd(char ch)
{
    if(ch == '(')
        return 1;
    if(ch == '+' || ch == '-')
        return 2;
    if(ch == '*' || ch == '/')
        return 3;
    if(ch == '^')
        return 4;
    return -1;
}
int isoperand(char ch)
{
    if(ch == ')' || ch == '(')
        return(0);
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return(0);
    return(1);
}
