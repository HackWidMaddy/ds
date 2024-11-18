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

int main(){
    struct Node * head =NULL;
    head = insert(head,1);
    head = insert(head,5);
    head = insert(head,3);
    head = insert(head,2);
    head = insert(head,4);
    head = insert(head,2);

    struct Node * left = NULL;
    struct Node * same = NULL;
    struct Node * right = NULL;
    int x = 3;
    struct Node * temp = head;
    while (temp != NULL)
    {
        if(temp->data == x){
            same = insert(same,temp->data);
        }
        else if(temp->data < x){
            left = insert(left,temp->data);
        }
        else{
            right = insert(right,temp->data);
        }
        temp =temp->next;
    }


    struct Node * hehe=  left;
    //merging
    while (hehe->next !=NULL)
    {
        hehe = hehe->next;
    }
    hehe->next = same;


    
    struct Node * hehe1=  left;
    //merging
    while (hehe1->next !=NULL)
    {
        hehe1 = hehe1->next;
    }
    hehe1->next = right;

    

    traversal(left);

 
    
return 0;
}