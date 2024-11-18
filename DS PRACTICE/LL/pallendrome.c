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


struct Node * reverse(struct Node * head){
    struct Node *first = NULL;
    struct Node *second = head;
    struct Node *third = NULL;
    while (second!=NULL)
    {
        third =second->next;
        second->next = first;
        first=second;
        second = third;
    }
    return first;

}

struct Node * clonner(struct Node *head){
    struct Node * temp = head;
    struct Node * clone=  NULL;
    while (temp!=NULL)
    {
        clone = insert(clone,temp->data);
        temp = temp->next;
    }

    return clone;
    
}


void checkpallendrone(struct Node * h1,struct Node * h2){
    struct Node * temp1 = h1;
    struct Node * temp2  =h2;
    int isPallendrome = 0;
    while (temp1 != NULL)
    {   
        if(temp1->data == temp2->data){
            isPallendrome = 1;
        }
        else{
            isPallendrome = 0;
            break;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    printf("%d",isPallendrome);
    
}

int main(){
    struct Node * head =NULL;
    head = insert(head,1);
    head = insert(head,2);
    head = insert(head,0);
    // head = insert(head,400);
    struct Node * clone = clonner(head);
   struct Node * revheadtemp = reverse(clone);
    traversal(head);
    printf("\n");
    traversal(revheadtemp);

 printf("\n");
 printf("\n");

 printf("\n");
    checkpallendrone(head,revheadtemp);
    
return 0;
}