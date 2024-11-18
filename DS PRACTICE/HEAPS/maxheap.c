#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int arr[MAX] = {0};
int size = 0;
void insert(int data){
    size = size + 1;
    int index = size;
    arr[index]  = data;
    while (index > 1)
    {
        int parent  = index/2;
        if(arr[parent] < arr[index]){
            int temp = arr[parent];
            arr[parent] = arr[index];
            arr[index] = temp;
            index= parent;
        }
        else{
            return;
        }
    }
           
}

void deletefron(){
    arr[1] = arr[size];
    size--;

    int i  = 0;
    while (i<size)
    {
    int leftchid  = 2*i;
    int rightchild  = 2*i+1;
    if(leftchid < size && arr[i] <arr[leftchid]){
        int temp = arr[leftchid];
        arr[leftchid] = arr[i];
        arr[i] = temp;
        i  = leftchid;
    }
    else if(rightchild < size ){
        int temp = arr[rightchild];
        arr[rightchild] = arr[i];
        arr[i] = temp;
        i  = rightchild;
    }
    else{
        return;
    }
    }
    
}


int main(){

    insert(50);
    insert(55);
    insert(53);
    insert(52);
    insert(54);
deletefron();
    for(int i =0;i<size;i++){
        printf("%d ",arr[i]);
    }
return 0;
}
