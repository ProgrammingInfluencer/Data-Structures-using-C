#include <stdio.h>
#include <stdlib.h>

typedef struct listnode_s{
    int data;
    struct listnode_s *next;
} listnode_t;
//Initialization of global variables
listnode_t  *firstnode = NULL;
listnode_t  *lastnode = NULL;

//functions declarations...
void push_back(const int data);
void push_front(const int data);
void insert(const int node, const int data);
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
    printf("first node: %d\n", get_front());
    printf("last node: %d\n", get_last());
   
    


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
void push_front(const int data)
{
    listnode_t *tmp = (listnode_t*)malloc(sizeof(listnode_t));
    tmp->data = data;
    if(firstnode == NULL)
    {
        firstnode = tmp;
        lastnode = tmp;
        tmp->next = NULL;
        return;
    }
    tmp->next = firstnode;
    firstnode = tmp;
}
void insert(const int node, const int data)
{
    if(node < 1 || size() < 1 || size() < node)
    {
        printf("Invalid Node\n");
        return;
    }
    listnode_t *tmp = (listnode_t*)malloc(sizeof(listnode_t));
    tmp->data = data;
    tmp->next = NULL;
    int i = 1;
    listnode_t *currnode = firstnode;
    while(currnode != NULL) //1->2->4, tmp->data = 3
    {
        if(node == i)
            break;
        else
        {
            currnode = currnode->next;
            i += 1;
        }
    }
    tmp->next = currnode->next; //3->next = 4
    currnode->next = tmp;    //2->next = 3 ,1->2->3->4
    free(currnode);
}
int size()
{
   int count = 0;
   listnode_t   *currnode = firstnode;
   while(currnode != NULL)
   {
        count += 1; 
        currnode = currnode->next;
   }
   free(currnode);
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
