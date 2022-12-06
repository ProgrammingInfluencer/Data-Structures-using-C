#include <stdio.h>
#include <string.h>
#define MAX 50
//Array Declaration
int arr[MAX];
int t = -1; //t is the index of top element
//function definition
void push(int data);
int pop();
int top();
int isempty();
int isfull();
int size();
int postfix_evaluation(char input[]); // to evaluate the postfix expression
int isoperand(char ch); // to check the given character is operand or not 
int operation(int a, int b, char ch); // to perform the given operation on a and b
int main()
{

    printf("%d\n", postfix_evaluation("821*-321/+-5^2+"));
    printf("%d\n", postfix_evaluation("32-"));
    printf("%d\n", postfix_evaluation("45+10-*"));
    return(0);
}
//function definitions
void push(int data)
{
    if(t == MAX-1)
    {
        printf("Stack is Overflow\n");
        return;
    }
    arr[++t] = data;
}
int pop()
{
    if(t == -1)
    {
        printf("Stack is Underflow\n");
        return(t);
    }
    return(arr[t--]); 
}
int top()
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
int postfix_evaluation(char input[])
{
    int i = 0;
    char in;
    int a, b, val;
    while(input[i] != '\0')
    {
        in = input[i];
        if(isoperand(in))
            push(in - '0'); 
        else
        {
            b = pop();
            a = pop();
            val = operation(a, b, in);
            push(val); 
        }
        i++;
    }
    return(pop());
}
int isoperand(char ch)
{
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return(0);
    return(1);
}
int operation(int a, int b, char ch)
{
    if(ch == '+')
        return(a + b);
    if(ch == '-')
        return(a - b);
    if(ch == '*')
        return(a*b);
    if(ch == '/')
        return(a/b);
    if(ch == '^')// a^b 
    {
        int pow = 1;
        while(b > 0)
        {
            pow *= a;
            b--;
        }
        return(pow);
    }
   return(-1); 
}
