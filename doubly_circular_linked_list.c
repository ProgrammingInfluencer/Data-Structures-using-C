#include <stdio.h>
#include <stdlib.h>

typedef struct listnode_s{
    struct listnode_s   *prev;
    int data;
    struct listnode_s   *next;
} listnode_t;

listnode_t *firstnode = NULL;
listnode_t *lastnode = NULL;
//function
void push_back(const int data);
void traverse_forward();
void traverse_backward();


int main()
{
    push_back(1);
    push_back(2);
    push_back(3);
    push_back(4);
    push_back(5);
    traverse_forward();
    traverse_backward();

    return(0);
}
void push_back(const int data)
{
    listnode_t *tmp = (listnode_t*)malloc(sizeof(listnode_t));
    tmp->prev = lastnode;
    tmp->data = data;
    tmp->next = firstnode;
    if(firstnode == NULL)
    {
        firstnode = tmp;
        lastnode = tmp;
        return;
    }
    tmp->prev = lastnode;
    lastnode->next = tmp;
    lastnode = lastnode->next;
    firstnode->prev = lastnode; 
}
void traverse_backward()
{
    if(firstnode == NULL)
    {
        printf("List is empty\n");
        return;
    }
    listnode_t *currnode = lastnode;
    do
    {
        printf("%d   ", currnode->data);
        currnode = currnode->prev;
    }while(currnode != lastnode);
    printf("%d   ", currnode->data);
    printf("\n");

}
void traverse_forward()
{
    if(firstnode == NULL)
    {
        printf("List is empty\n");
        return;
    }
    listnode_t *currnode = firstnode;
    do
    {
        printf("%d   ", currnode->data);
        currnode = currnode->next;
    }while(currnode != firstnode);
    printf("%d   ", currnode->data);
    printf("\n");

}


/* Subscribe Programming Influencer  */
