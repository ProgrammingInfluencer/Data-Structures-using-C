/*  Implementation of stack using linked list  */

#include <stdio.h>
#include <stdlib.h>

//structure of a node
typedef struct node_s{
    int data;
    struct node_s *next;
} node_t;
//declaration of variables
node_t *t = NULL;
int count = -1;
//function of stack
void push(int data);
int pop();
int top();
int isempty();
int size();

int main()
{
    printf("Is empty ? %d\n", isempty());
    printf("Size: %d\n", size()); //0
    push(1);
    push(2);
    push(3);
    push(100);
    push(2000);
    push(23);
    push(25);
    printf("Is empty ? %d\n", isempty());
    printf("Size: %d\n", size()); //7
    while(!isempty())
    {
        printf("Top:%d\n", top());
        pop();
    } 
    pop();
    printf("Is empty ? %d\n", isempty());
    printf("Size: %d\n", size()); //0
    return(0);
}
void push(int data)
{
  node_t *tmp = (node_t*)malloc(sizeof(node_t)); 
  tmp->data = data;
  tmp->next = NULL;
  count += 1;
  if(t == NULL)
  {
    t = tmp;
    return;
  }
  tmp->next = t;
  t = tmp;
}
int pop()
{
    node_t  *currnode = t;
    int val = -1;
    if(isempty())
    {
        printf("Stack is empty!!!\n");
        return(val);
    }
    count -= 1;
    if(t->next == NULL)
    {
        t = NULL;
        val = currnode->data;
        free(currnode);
        return(val);
    }
    t = t->next;
    val = currnode->data;
    free(currnode);
    return(val);
}
int top()
{
    if(isempty())
        return(-1);
    return(t->data);
}
int isempty()
{
    return(t == NULL);   
}
int size()
{
    return(count + 1);
}
//Programming Influencer
