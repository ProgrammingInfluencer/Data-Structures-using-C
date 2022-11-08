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
void traverse();
void detect_cycle();

int main()
{
    int i;
   
    for(i = 0; i < 5; i++)
    {
        push_front(i + 10);
    } 
    traverse();
    pop_back();
    traverse();
    


    return(0);
}
//function definitions...
void push_back(const int data)
{
    listnode_t  *tmp = (listnode_t*)malloc(sizeof(listnode_t));
    tmp->data = data;
    tmp->next = firstnode;
    if(firstnode == NULL)
    {
        firstnode = tmp;
        lastnode = tmp;
        return;
    }
    lastnode->next = tmp;
    lastnode = lastnode->next;
}
void traverse() 
{
    if(firstnode == NULL)
    {
        printf("List is empty!\n");
        return;
    }
    int i = 1;
    listnode_t *currnode = firstnode;
    do
    {
        printf("Node%d:%d   ", i, currnode->data);
        currnode = currnode->next;
        i += 1;
    }while(currnode != firstnode);
    printf("Node%d:%d   ", i, currnode->data);
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
void detect_cycle()
{
    if(lastnode->next == firstnode)
        printf("List has a cycle\n");
    else
        printf("List has no cycle\n");
}



//Programming Influencer
//Subscribe our channel
