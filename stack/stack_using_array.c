#include <stdio.h>
#define MAX 10
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

int main()
{
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    push(100);
    while(!isempty()) 
    {
        printf("%d\n", pop());
    }
    pop();
    printf("Size of the stack is: %d\n", size());
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
