#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
    struct Node * prev;

};
struct Node* newnode(int data){
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

struct Node * insert(struct Node *head,int data){
    if(head == NULL){
        return newnode(data);
    }

    struct Node * temp = head;
    while (temp->next !=NULL)
    {
        temp = temp->next;
    }
    struct Node * new = newnode(data);
    temp->next = new;
    new->prev = temp;
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


struct Node * insertafterposition(struct Node* head,int data,int index){
    if(head ==NULL){
        return newnode(data);
    }
    if(index == 0){
        struct Node * test=  newnode(data);
        test->prev = NULL;
        test->next = head;
        head = test;
        return head;
    }
    struct Node * temp=head;
    for(int i =0;i<index-1;i++){
        if(temp->next == NULL){
            temp->next = newnode(data);
            return head;
        }
        temp  = temp->next;
    }

    struct Node * new = newnode(data);
    struct Node * nexter= temp->next;
    nexter->prev = new;
    new->next = temp->next;
    temp->next = new;

    return head;

}


struct Node * concatinate(struct Node * head,struct Node* head2){
    struct Node * new =head;
    struct Node * temp =head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next = head2;

    return head;
    

}
int main(){
    struct Node * head =NULL;
    struct Node * head2 =NULL;

    head = insert(head,100);
    head = insert(head,200);
    head = insert(head,300);
    head = insertafterposition(head,500,1);
 
    
    head2 = insert(head2,100);
    head2 = insert(head2,200);
    head2 = insert(head2,300);
    head2 = insertafterposition(head2,500,1);
    

    struct Node * temp =concatinate(head,head2);


    traversal(temp);
return 0;
}