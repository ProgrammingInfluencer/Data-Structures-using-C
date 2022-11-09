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
void pop_back() //O(n)
{
/*delete an element from the end of list*/ 
//In case list is empty
    if(firstnode == NULL)
        return;
//if list has only single node
    listnode_t *currnode = firstnode;
    if(firstnode->next == NULL)
    {
        firstnode = NULL;
        lastnode = NULL;
        free(currnode);
        return;
    }
//if our list has more than one node
    while(currnode->next->next != NULL)
    {
        currnode = currnode->next;
    }
    lastnode = currnode;
    lastnode->next = NULL;
    currnode = currnode->next;
    free(currnode);
   
}
void pop_front() //O(1)
{
//Delete an element from the beginning of list
//if list is empty
    if(firstnode == NULL)
        return;
    listnode_t *currnode = firstnode;
//If list has single node
    if(firstnode->next == NULL)
    {
        firstnode = NULL;
        lastnode = NULL;
        free(currnode);
        return;
    }
//if list has more than one node
    firstnode = firstnode->next;
    free(currnode);
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

int getData(listnode_t *node)
{
    return(node->data);
}
int get_front()
{
    return getData(firstnode);
}
int get_last()
{
    return getData(lastnode);
}

//Programming Influencer
//Subscribe our channel
