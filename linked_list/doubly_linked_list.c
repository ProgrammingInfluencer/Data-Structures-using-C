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
void pop_back();

int main()
{
    push_back(1);
    push_back(2);
    push_back(3);
    push_back(4);
    push_back(5);
    traverse_forward();
    pop_back();
    pop_back();
    pop_back();
    pop_back();
    pop_back();
    traverse_forward();
   // traverse_backward();

    return(0);
}
void push_back(const int data)
{
    listnode_t *tmp = (listnode_t*)malloc(sizeof(listnode_t));
    tmp->prev = NULL;
    tmp->data = data;
    tmp->next = NULL;
    if(firstnode == NULL)
    {
        firstnode = tmp;
        lastnode = tmp;
        return;
    }
    tmp->prev = lastnode;
    lastnode->next = tmp;
    lastnode = lastnode->next;  
}
void traverse_backward()
{
    if(firstnode == NULL)
    {
        printf("List is empty\n");
        return;
    }
    listnode_t *currnode = lastnode;
    while(currnode != NULL)
    {
        printf("%d   ", currnode->data);
        currnode = currnode->prev;
    }
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
    while(currnode != NULL)
    {
        printf("%d   ", currnode->data);
        currnode = currnode->next;
    }
    printf("\n");

}
void pop_back()
{
    if(firstnode == NULL)
        return;
    listnode_t *currnode = lastnode;
    if(firstnode == lastnode)
    {
        firstnode = NULL;
        lastnode = NULL;
        free(currnode);
        return;
    }
    lastnode = currnode->prev;
    lastnode->next = NULL;
    free(currnode);
}

/* Subscribe Programming Influencer  */
//      1->2->3->4
// *prev,data,*next
