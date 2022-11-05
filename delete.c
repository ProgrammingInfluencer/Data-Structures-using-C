/* This is the implementation of delete() function */

#include <stdio.h>
#include <stdlib.h>

typedef struct listnode_s{
    int data;
    struct listnode_s *next;
} listnode_t;
listnode_t  *firstnode = NULL;
listnode_t  *lastnode = NULL;
//functions....
void push_back(const int data);
void pop_back();
void pop_front();
void delete(const int node);
void clearList();
int get_front();
int get_last();
int getData();
int getmid();
int size();
void traverse();


int main()
{
    int i;
   
    for(i = 0; i < 5; i++)
    {
        push_back(i + 10);
    } 
    traverse();
    delete(13);
    traverse();
    
    
    return(0);
}
//function definitions...
void push_back(const int data)
{
    listnode_t  *tmp = (listnode_t*)malloc(sizeof(listnode_t));
    tmp->data = data;
    tmp->next = NULL;
    if(firstnode == NULL)
    {
        firstnode = tmp;
        lastnode = tmp;
        return;
    }
    lastnode->next = tmp;
    lastnode = lastnode->next;
}

void delete(const int node)
{
 /*Delete the given node*/
    if(firstnode == NULL)
        return;
    if(firstnode == lastnode &&
    firstnode->data != node)
        return;
    listnode_t *currnode = firstnode;
    listnode_t *tmp = NULL;
    while(currnode->next != NULL)
    {
        if(currnode->next->data == node)
            break;
        currnode = currnode->next;
    }
    if(currnode == lastnode && currnode->data != node)
    {
        printf("Given Element is not present in the list\n");
        return;
    }
    tmp = currnode->next;
    currnode->next = currnode->next->next;
    free(tmp);
}

void traverse() //Node1:1
{
    if(firstnode == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    int i = 1;
    listnode_t *currnode = firstnode;
    while(currnode != NULL)
    {
        printf("Node%d:%d   ", i, currnode->data);
        currnode = currnode->next;
        i += 1;
    }
    free(currnode);
    printf("\n");
}


/*        Programming Influencer
          Subscribe our channel        */
