// #include<stdio.h>
// #include<stdlib.h>
// struct Node{
//     struct Node * right;
//     struct Node * left;
//     int data;
//     int height;
// };

// struct Node * newnode(int data){
//     struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
//     temp->right=NULL;
//     temp->left= NULL;
//     temp->data=  data;
//     temp->height = 0;
//     return temp;
// }

// int height(struct Node  *root){
//     if(root == NULL){
//         return 0;
//     }
//     return root->height;
// }


// int getbalancefacotr(struct Node * node){
//     if(node==NULL){
//         return 0;
//     }
//     return height(node->left) - height(node->right);
// }

// struct Node* leftrotation(struct Node * root){
//     struct Node * y = root->right;
//     struct Node * T2 = y->left;
//     //perform rotation
//     y->left=root;
//     root->right = T2;
//     int leftheight = height(root->left);
//     int rightheight = height(root->right);
//     if(leftheight>rightheight){
//         root->height = leftheight + 1;
//     }
//     else{
//         root->height= rightheight +1;
//     }

//     leftheight = height(y->left);
//     rightheight = height(y->right);
//     if(leftheight>rightheight){
//         y->height = leftheight + 1;
//     }
//     else{
//         y->height= rightheight +1;
//     }

//     return y;

// }



// struct Node* rightrotsation(struct Node * root){
//     struct Node * y = root->left;
//     struct Node * T2 = y->right;
//     //perform rotation
//     y->right=root;
//     root->left = T2;
//     int leftheight = height(root->left);
//     int rightheight = height(root->right);
//     if(leftheight>rightheight){
//         root->height = leftheight + 1;
//     }
//     else{
//         root->height= rightheight +1;
//     }

//     leftheight = height(y->left);
//     rightheight = height(y->right);
//     if(leftheight>rightheight){
//         y->height = leftheight + 1;
//     }
//     else{
//         y->height= rightheight +1;
//     }

//     return y;

// }

// struct Node * insert(struct Node * root,int data){
//     if(root == NULL){
//         return newnode(data);
//     }

//     if(data < root->data){
//         root->left = insert(root->left,data);
//     }
//     else if(data > root->data){
//         root->right = insert(root->right,data);
//     }
//     else{
//         return root;
//     }

//     int leftheight = height(root->left);
//     int rightheight = height(root->right);
//     if(leftheight>rightheight){
//         root->height = leftheight+1;
//     }
//     else{
//         root->height = rightheight+1;
//     }

//     int balance = getbalancefacotr(root);

//     if(balance< -1 && data > root->right->data){
//         return leftrotation(root);
//     }

//     if(balance > 1 && data < root->left->data){
//         return rightrotsation(root);
//     }

//     return root;
// }

// void inorder(struct Node * root){
//     if (root==NULL)
//     {
//         return;
//     }

//     inorder(root->left);
//     printf("%d ",root->data);
//     inorder(root->right);    
// }
// int main(){
//     struct Node *root = NULL;
//     root= insert(root,10);
//     root= insert(root,5);
//     root= insert(root,6);
//     root= insert(root,4);

//     // root= insert(root,30);
//     // root= insert(root,30);
// inorder(root);

 
// return 0;
// }



#include<stdio.h>
#include<stdlib.h>
struct Node{
    struct Node * right;
    struct Node * left;
    int data;
    int height;
};

struct Node * newnode(int data){
    struct Node * temp = (struct Node*)malloc(sizeof(struct Node));
    temp->height = 0;
    temp->right = NULL;
    temp->left = NULL;
    temp->data = data;
    return temp;
}

int height(struct Node* temp){
    if(temp==NULL){
        return 0;
    }
    return temp->height;
}


int getbalance(struct Node * root){
    if(root==NULL){
        return 0;
    }
    return height(root->left) - height(root->right);
}



struct Node * rightrot(struct Node *root){
    struct Node * y = root->right;
    struct Node * T2 = y->left;
    //dorotate
    y->left=root;
    root->right = T2;
    //calcheight
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    if(leftheight>rightheight){
        root->height = leftheight +1;
    }
    else{
        root->height = rightheight +1;
    }


    leftheight = height(y->left);
    rightheight = height(y->right);
    if(leftheight>rightheight){
        y->height = leftheight +1;
    }
    else{
        y->height = rightheight +1;
    }

    return y;
}




struct Node * leftrot(struct Node *root){
    struct Node * y = root->left;
    struct Node * T2 = y->right;
    //dorotate
    y->right=root;
    root->left = T2;
    //calcheight
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    if(leftheight>rightheight){
        root->height = leftheight +1;
    }
    else{
        root->height = rightheight +1;
    }


    leftheight = height(y->left);
    rightheight = height(y->right);
    if(leftheight>rightheight){
        y->height = leftheight +1;
    }
    else{
        y->height = rightheight +1;
    }

    return y;
}

struct Node * insert(struct Node *root,int data){
    if(root == NULL){
        return newnode(data);
    }

    if(data < root->data){
        root->left = insert(root->left,data);
    }
    else if(data > root->data){
        root->right = insert(root->right,data);
    }
    else{
        return root;
    }

    int leftheight = height(root->left);
    int rightheight = height(root->right);
    if(leftheight>rightheight){
        root->height = leftheight +1;
    }
    else{
        root->height = rightheight +1;
    }


    int balance = getbalance(root);
    if (balance < -1 && data > root->right->data){
        return rightrot(root);
    }


    if(balance> 1 && data < root->left->data){
        return leftrot(root);
    }
    
    return root;
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

int main(){
    struct Node * root= NULL; 
    root = insert(root,10);
    root = insert(root,5);
    root = insert(root,6);

    root = insert(root,4);


    inorder(root);
 
return 0;
}