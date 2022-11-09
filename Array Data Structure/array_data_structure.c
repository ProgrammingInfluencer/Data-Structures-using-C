#include <stdio.h>
#define  MAX     10

int size = 0;
void Insert(int arr[], int data, int index); //O(n)
void Traverse(int arr[]); //O(n)
void Delete(int arr[], int data); //O(n)

int main()
{
    int arr[MAX];
    Insert(arr, 100, 0);
    Insert(arr, 200, 1);
    Insert(arr, 300, 2);
    Insert(arr, 400, 3);
    Insert(arr, 500, 4);
    Delete(arr, 500);
    Delete(arr, 400);
    Delete(arr, 300);
    Delete(arr, 200);
    Delete(arr, 100); 
    Delete(arr, 500);  
    
    printf("After Deletion :\n");
    Traverse(arr);


    return 0;
}

void Insert(int arr[], int data, int index)
{
    int i = 0;
    if(index > MAX - 1)
    {
        printf("Invalid index\n");
        return;
    }
    if(size == index) //insertion at end
    {
        arr[index] = data;
        size += 1;
        return;
    }
    size += 1;
    i = size;
    while(i > index)  // shift all the element one space to the right
    {
        arr[i] = arr[i-1];
        i -= 1;
    }
    arr[index] = data;
   
}
void Traverse(int arr[])
{
    if(size == 0)
    {
        printf("There is no any element present in array\n");
        return;
    }
    int i;
    for(i = 0; i < size; i++)
    {
        printf("Array[%d] = %d\n", i, arr[i]);  //Array[0] = data
    }
    
}
void Delete(int arr[], int data) //O(n + n) = O(n)
{
    int i, pos = -1;
    for(i = 0; i < size; i++)
    {
        if(data == arr[i]) {
            pos = i;
            break;
        }
            
    }
    if(pos == -1)
    {
        printf("Element is not present in Array\n");
        return;
    }
    while(pos < size - 1)
    {
        arr[pos] = arr[pos + 1]; //arr[4] = arr[5]
        pos += 1;
    }
    size -= 1;
}
