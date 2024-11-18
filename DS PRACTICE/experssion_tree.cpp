#include<iostream>
#include<stack>
using namespace std;
struct Node {
    struct Node * left;
    struct Node * right;
    char data;
};
struct Node * newnode(char data){
        struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
        temp->left = NULL;
        temp->right = NULL;
        temp->data = data;
        return temp;
}

int isOperator(char data){
    if(data == '+' || data == '-' || data == '*' || data == '/' || data == '%'){
        return 1;
    }

    return 0;
}

void inorder(struct Node* root){
    if(root==NULL){
        return;
    }


    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);


}

stack<struct Node*> s;
int main(){
    char experssion[] = "ab+cde+**";
    int counter = 0;
    while (experssion[counter] != '\0')
    {   
        if(!isOperator(experssion[counter])){
            s.push(newnode(experssion[counter]));
            counter++;
        }
        else{
            struct Node * temp1 = s.top();
            s.pop();
            struct Node * temp2 = s.top();
            s.pop();
            struct Node * myoperator = newnode(experssion[counter]);
            myoperator->right=temp1;
            myoperator->left = temp2;
            s.push(myoperator);
            counter++;
        }

    }


    struct Node * root = s.top();
    inorder(root);
    

    return 0;
}



