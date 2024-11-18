#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node * next;
    int exp;
};

struct Node* newnode(int data,int exp){
    struct Node * newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->exp = exp;
    newnode->next = NULL;
    return newnode;
}

struct Node * insert(struct Node * head,int data,int exp){
    if(head == NULL){
        return newnode(data,exp);
    }

    struct Node * temp = head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next = newnode(data,exp);
    return head;    
}


// struct Node * sortedinsert(struct Node * head,int data){
//     if(head == NULL){
//         return newnode(data);
//     }

//     struct Node * temp = head;
//     while (temp->next!=NULL)
//     {
//         if(temp->data < data && temp->next->data > data){
//             break;
//         }
//         temp=temp->next;
//     }
//     struct Node * new = newnode(data);
//     // new->nex=
//     new->next = temp->next;
//     temp->next = new;
//     return head;    
// }



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

struct Node * polycalc(struct Node * total,struct Node * h1,struct Node * h2){
    struct Node * temp1 = h1;
    struct Node * temp2 = h2;

    while (temp1!=NULL || temp2!=NULL)
    {
        if(temp1->exp == temp2->exp){
            total = insert(total,temp1->data + temp2->data,temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->exp > temp2->exp){
            total = insert(total,temp1->data,temp1->exp);
            temp1 = temp1->next;
        }
        else{
            total = insert(total,temp2->data,temp2->exp);
            temp2 = temp2->next;
        }
    }

    return total;

    

}
int main(){
    struct Node * head =NULL;
    head = insert(head,4,3);
    head = insert(head,3,2);
    head = insert(head,2,1);
    head = insert(head,1,0);


    struct Node * head2 = NULL;
    head2 = insert(head2,5,3);
    head2 = insert(head2,6,1);
    head2 = insert(head2,2,0);

    struct Node * total = NULL;
    total = polycalc(total,head,head2);

    traversal(total);

 
    
return 0;
}