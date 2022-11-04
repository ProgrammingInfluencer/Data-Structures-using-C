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
    pop_front();
    traverse();
    pop_front();
    traverse();
    pop_front();
    traverse();
    pop_front();
    traverse();
    pop_front();
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
void pop_back() 
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
