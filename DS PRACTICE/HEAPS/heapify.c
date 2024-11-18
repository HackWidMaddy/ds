#include<stdio.h>
#include<stdlib.h>
void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right= 2*i+1;
    
    if(left < n && arr[left] > arr[largest]){
        largest = left;
    }

    if(right< n && arr[right] > arr[largest]){
        largest = right;
    }
    if(largest!=i){
        int temp = arr[largest];
        arr[largest] = arr[i];
        arr[i] = temp;
        heapify(arr,n,largest);
    }

}

int main(){
    int arr[] = {4, 10, 3, 5, 1};
    int n = 5;

    for(int i = n/2 - 1;i>=0;i--){
        heapify(arr,n,i);
    } 


    for(int i = 0;i<5;i++){
        printf("%d ",arr[i]);
    }
return 0;
}