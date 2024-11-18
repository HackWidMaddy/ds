// #include<stdio.h>
// #include<stdlib.h>
// struct Node{
//     struct Node *right;
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

// struct Node * bstinsertion(struct Node * root,int data){
//     if(root == NULL){
//         return newnode(data);
//     }

//     if(data>root->data){
//         root->right = bstinsertion(root->right,data);
//     }
//     else{
//         root->left = bstinsertion(root->left,data);
//     }
//     return root;
// }
// void bstsearch(struct Node *root,int key){
//     if(root==NULL){
//         printf("\nKEY NOT FOUND\n");
//         return;
//     }
//     else if (root->data == key)
//     {
//         printf("\nKEY FOUND\n");
//         return;
//     }
    

//     if(key>root->data){
//         bstsearch(root->right ,key);
//     }
//     else{
//         bstsearch(root->left ,key);
//     }

// }

// void inorder(struct Node * root){
//     if(root==NULL){
//         return;
//     }
//     inorder(root->left);
//     printf("%d " , root->data);
//     inorder(root->right);
// }

// int findmaximum(struct Node * root){
//     if(root->right==NULL){
//         return root->data;
//     }

//     findmaximum(root->right);
// }


// int findminimum(struct Node * root){
//     if(root->left==NULL){
//         return root->data;
//     }

//     findminimum(root->left);
// }

// int main(){
//     struct Node * root = NULL;
//     root = bstinsertion(root,10);
//     root = bstinsertion(root,20);
//     root = bstinsertion(root,30);
//     root = bstinsertion(root,10);
//     root = bstinsertion(root,1);
//     root = bstinsertion(root,-100);


//     // inorder(root);
//     // bstsearch(root,30);
//     printf("%d ", findmaximum(root));
//     printf("\n%d ",findminimum(root));
//     return 0;
// }
#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node *right;
    struct Node *left;
    int data;
};
struct Node *newnode(int data){
    struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
    temp->right = NULL;
    temp->left= NULL;
    temp->data = data;
    return temp;
}

struct Node * insert(struct Node * root,int data){
    if(root == NULL){
        return newnode(data);
    }

    if(root->data > data){
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }

    return root;
}

int found = 0;
void search(struct Node * root,int data){
    if(root == NULL){
       return;
    }
    if(root->data==data){
        found=1;
    }

    if(root->data > data){
       search(root->left,data);
    }
    else{
        search(root->right,data);
    }

}


void inorder(struct Node * root){
    if (root==NULL)
    {
        return;
    }


    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);    
}
int maini;
void findmin(struct Node * root){
    while (root->left !=NULL)
    {
        root=root->left;
    }
    printf("%d",root->data);
    
}
// struct Node* findSuccessor(struct Node* root, int finder) {
//     struct Node* successor = NULL;

//     // Traverse the tree to find the node and its successor
//     while (root != NULL) {
//         if (finder < root->data) {
//             // If the node's data is smaller, update successor and move left
//             successor = root;
//             root = root->left;
//         }
//         else if (finder >= root->data) {
//             // If the node's data is larger, move right
//             root = root->right;
//         }
//         else {
//             // The node has been found
//             break;
//         }
//     }

//     // If the node has a right subtree, find the leftmost node in that subtree
//     if (root != NULL && root->right != NULL) {
//         root = root->right;
//         while (root->left != NULL) {
//             root = root->left;
//         }
//         successor = root;
//     }

//     return successor;
// }



void findSuccessor(struct Node * root,int finder){

struct Node * successor;

    while (root!=NULL)
    {
        if(finder < root->data){
            successor=root;
            root = root->left;
        }
        else if(finder > root->data){
            root  =root->right;
        }
        else{
            break;
        }
    }


    if(root->right != NULL){
        root = root->right;
        while (root->left!=NULL)
        {
            root =root->left;
        }

        successor = root;
        
    }


    printf("%d",successor->data);
    


}


void predecessor(struct Node * root,int finder){
    struct Node * pred;

    while (root!=NULL)
    {
        if (finder>root->data)
        {
            pred =root;
            root = root->right;
        }
        else if(finder < root->data){
            root = root->left;
        }
        else{
            break;
        }
        
    }

    if(root->left!=NULL){
        root = root->left;
        while (root->right!=NULL)
        {
            root = root->right;
        }

        pred=root;
        
    }
    

    printf("%d",pred->data);
}




int main(){
    struct Node * root= NULL;
    root = insert(root,20);
    root = insert(root,8);
    root = insert(root,22);
    root = insert(root,4);
    root = insert(root,12);
    root = insert(root,10);
    root = insert(root,14);


    // inorder(root);
findSuccessor(root,10);
printf("\n");
predecessor(root,10);


    // search(root,5);
    // printf("%d",found);
    // findmin(root);
    return 0;
}