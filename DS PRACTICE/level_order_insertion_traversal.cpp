// #include<iostream>
// #include<stdlib.h>
// #include<queue>
// using namespace std;
// struct Node{
//     struct Node * right;
//     struct Node * left;
//     int data;
// };
// struct Node * newnode(int data){
//     struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
//     temp->right = NULL;
//     temp->left = NULL;
//     temp->data = data;
//     return temp;
// }

// queue<struct Node*> q;
// struct Node *insert(struct Node * root,int data){
//     if(root == NULL){
//         return newnode(data);
//     }
//     q.push(root);
//     while(!q.empty()){
//         struct Node * temp = q.front();
//         q.pop();
//         if(temp->left == NULL){
//             temp->left = newnode(data);
//             return root;
//         }
//         else{
//             q.push(temp->left);
//         }
        
        
//         if(temp->right==NULL){
//             temp->right = newnode(data);
//             return root;
//         }
//         else{
//             q.push(temp->right);
//         }
//     }

//     return root;
// }


// void inorder(struct Node * root){
//     if(root==NULL){
//         return;
//     }


//     inorder(root->left);
//     cout<<root->data<<" ";
//     inorder(root->right);
// }

// int noofleaves = 0;
// void countnoofleavesinbinarytree(struct Node * root){
//     if(root==NULL){
//         return;
//     }


//     countnoofleavesinbinarytree(root->left);
//     if(root->left == NULL && root->right == NULL){
//         noofleaves  =noofleaves + 1;
//     }
//     countnoofleavesinbinarytree(root->right);

// }
// int totalnodes = 0;
// void calculatetotalnoofnodes(struct Node * root){
//     if(root == NULL){
//         return;
//     }
//     totalnodes++;
//     calculatetotalnoofnodes(root->left);
//     calculatetotalnoofnodes(root->right);

// }

// int main(){
//     struct Node * root = NULL;
//     root = insert(root,10);
//     root = insert(root,20);
//     root = insert(root,30);
//     root = insert(root,40);
//     root = insert(root,50);
//     // root = insert(root,60);
//     // root = insert(root,70);

//     // inorder(root);
//     countnoofleavesinbinarytree(root);
//     calculatetotalnoofnodes(root);
//     printf("NO OF NOTES ARE: %d",totalnodes);

//     // printf("NO OF LEAVES ARE: %d",noofleaves);
//     return 0;
// }

#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;
struct Node {
    struct Node * right;
    struct Node * left;
    int data;
};


struct Node * newnode(int data){
    struct Node * temp= (struct Node*)malloc(sizeof(struct Node));
    temp->right = NULL;
    temp->left = NULL;
    temp->data = data;
    return temp;
}
struct Node * insert(struct Node * root,int data){
    if(root == NULL){
        return newnode(data);
    }

    queue<struct Node *> q;
    q.push(root);
    while (!q.empty())
    {
        struct Node * tempr = q.front();
        q.pop();
        if(tempr->left==NULL){
            tempr->left = newnode(data);
            return root;
        }
        else{
            q.push(tempr->left);
        }

        if(tempr->right == NULL){
            tempr->right = newnode(data);
            return root;
        }
        else{
            q.push(tempr->right);
        }
    }
    return root;
}

void inorder(struct Node * root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int height(struct Node * root){
    if(root == NULL){
        return -1;
    }

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    if(leftheight>rightheight){
        return leftheight +1;
    }
    else{
        return rightheight +1;
    }

}
int main(){
    struct Node * root = NULL;
    root = insert(root,10); 
    root = insert(root,20);   
    root = insert(root,30);   
    root = insert(root,40);   
    printf("%d",height(root));
    // inorder(root);
}