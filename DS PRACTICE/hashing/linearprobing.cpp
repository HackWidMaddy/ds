#include<vector>
#include<iostream>
using namespace std;
struct Node{
    struct Node * next;
    int data;
};
vector<struct Node *> s1;

struct Node* newnode(int data){
    struct Node * temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
void init(){
    for(int i =0;i<=5;i++){
        s1.push_back(newnode(i));
    }
}
void insert(int data){
    int mode = data%11;
    struct Node * temp =s1[mode];
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode(data);
    
    
}


void searching(int data){
    int found = 0;
    int mode = data%11;
 struct Node * temp =s1[mode];
    while (temp!=NULL)
    {
        if(temp->data == data){
            found = 1;
            break;
        }
        temp = temp->next;
    }
    printf("founder %d ",found);

}

int main(){
    init();
insert(12);
insert(34);


for(int i = 0;i<=5;i++){
    struct Node * temp = s1[i];
    // printf("%d -> ",s1[i]->data);
    while (temp!=NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

printf("\n");
searching(324);


}