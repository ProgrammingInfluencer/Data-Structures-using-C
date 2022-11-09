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
    delete(100);
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
int size()
{
/* This function will return number of 
nodes in the list */ 
    int count = 0;
    if(firstnode == NULL)
        return(count);
    listnode_t *currnode = firstnode;
    while(currnode != NULL)
    {
        count += 1;
        currnode = currnode->next;
    }
    return(count);
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
int getmid()
{
    if(firstnode == NULL)
        return(0);
    if(firstnode == lastnode)
        return(firstnode->data);
    listnode_t  *currnode1 = firstnode;
    listnode_t  *currnode2 = firstnode;
    while(currnode2 != NULL && currnode2->next != NULL)
    {
        currnode1 = currnode1->next;
        currnode2 = currnode2->next->next;
    }
    return(currnode1->data);
}



//Programming Influencer
//Subscribe our channel
