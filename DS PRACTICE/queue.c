#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int front;
    int rear;
    int size;
    int  *arr;
};

void init(struct Queue * s1){
    s1->front  = -1;
    s1->rear = = -1;
    s1->size= 10;
    s1->arr = (int *)malloc(sizeof(int) * s1->size);
}
int peek(struct Queue *s1){
    return s1->arr[s1->front];
}

int isFull(struct Queue *s1){
    if(s1->rear == s1->size -1){
        return 1;
    }
    return 0;   
}

int isEmpty(struct Queue *s1){
    if(s1->front == -1){
        return 1;
    }
    return 0;   
}

void enqueue(struct Queue *s1,int data){
    if(isFull(s1)){
        printf("OVERFLOW");
        return;
    }
    else{
        if(s1->front == -1){
            s1->front++;
        }
        s1->rear++;
        s1->arr[s1->rear] = data;
    }
}



void deenqueue(struct Queue *s1,int data){
    if(isEmpty(s1)){
        printf("OVERFLOW");
        return;
    }
    int data = s1->arr[s1->front];
    
}


int main(){
 
 
return 0;
}