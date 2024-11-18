#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
};

struct Node* newnode(int data){
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct Node * insert(struct Node * head,int data){
    if(head == NULL){
        return newnode(data);
    }

    struct Node * temp = head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = newnode(data);
    return head;    
}


struct Node * sortedinsert(struct Node * head,int data){
    if(head == NULL){
        return newnode(data);
    }

    struct Node * temp = head;
    while (temp->next!=NULL)
    {
        if(temp->data < data && temp->next->data > data){
            break;
        }
        temp=temp->next;
    }
    struct Node * new = newnode(data);
    // new->nex=
    new->next = temp->next;
    temp->next = new;
    return head;    
}



void traversal(struct Node * head){
    struct Node* temp =head;
    while (temp!=NULL)
    {
        printf("\n%d",temp->data);
        temp = temp->next;
    }
    
}

struct Node* removeduplicate(struct Node * head){
    struct Node * temp = head;
    while (temp->next!=NULL)
    {
        if(temp->next->data == temp->data){
            struct Node * deleteit = temp->next;
            temp->next = deleteit->next;
            free(deleteit);
        }
        else{

        temp = temp->next;
        }
    }
    



    return head;
}

struct Node * swapping(struct Node * head){
    struct Node * temp = head;
    struct Node * temp1 = head;
    
    while (temp!=NULL)
    {
        temp1 = temp->next;
        temp->next =  temp1->next;
        temp1->next= temp;
        temp = temp->next;
    }

    return head;
    
}

int main(){
    struct Node * head =NULL;
    head = insert(head,100);
    head = insert(head,200);
    head = insert(head,300);
    head = insert(head,400);
    head = swapping(head);
    traversal(head);

 
    
return 0;
}