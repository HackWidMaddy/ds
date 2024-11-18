// #include<stdio.h>
// #include<stdlib.h>
// struct Stack{
//     char *arr;
//     int top;
//     int size;
// };

// void initialize(struct Stack *s1){
//     s1->size = 10;
//     s1->arr= (char *)malloc(sizeof(char) * s1->size);
//     s1->top = -1;
// }


// void push(struct Stack * s1, char data){
//     s1->top = s1->top + 1;
//     s1->arr[s1->top] = data;
// }   
// char pop(struct Stack *s1){
//     char temp = s1->arr[s1->top];
//     s1->top = s1->top-1;
//     return temp;
// }
// int isOperator(char data){
//     if(data == '+' || data == '-' || data=='*' || data == '/' || data=='^'){
//         return 1;
//     }
//     return 0;
// }

// int isEmpty(struct Stack *s1){
//     if(s1->top == -1){
//         return 1;
//     }
//     return 0;
// }


// int preceddence(char data){
//     if(data == '^'){
//         return 2;
//     }
//     else if(data == '*' ||data == '/' ){
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }


// char peek(struct Stack * s1){
//     return s1->arr[s1->top];
// }

// int main(){
//     struct Stack * s1 = (struct Stack*)malloc(sizeof(struct Stack));
//     initialize(s1);
//     char expression[] = "a+b";
//     int counter = 0;
//     while (expression[counter] != '\0')
//     {
//         if(!isOperator(expression[counter])){
//             printf("%c",expression[counter]);
//             counter++;
//         }
//         else{
//                 if(isEmpty(s1)){
//                     push(s1,expression[counter]);
//                     counter++;
//                 }
//                 else if(preceddence(expression[counter]) > preceddence(peek(s1))){
//                     push(s1,expression[counter]);
//                     counter++;
//                 }
//                 else{
//                     while (1)
//                     {
//                         if(isEmpty(s1)){
//                             break;
//                         }
//                         else if(preceddence(expression[counter]) > preceddence(peek(s1))){
//                             break;
//                         }

//                         printf("%c",pop(s1));
//                     }
                    
//                 }
//         }
//     }
    
//     while (!isEmpty(s1))
//     {
//         printf("%c",pop(s1));
//     }
    
// return 0;
// } 

#include<stdio.h>
#include<stdlib.h>
struct Stack{
    char *arr;
    int top;
    int size;
};
void init(struct Stack *s1){
    s1->size=10;
    s1->arr = (char *)malloc(sizeof(char) * s1->size);
    s1->top = -1; 
};

int isOperator(char data){
    if (data == '+' || data == '-' || data == '*' ||data == '/' ||data == '^')
    {
        return 1;
    }
    return 0;
    
}

void push(struct Stack *s1,char data){
    s1->top = s1->top + 1;
    s1->arr[s1->top]  = data;
}
int isEmpty(struct Stack * s1){
    if(s1->top==-1){
        return 1;
    }
    return 0;
}

int precedence(char data){
    if(data == '^'){
        return 3;
    }
    else if(data == '*' || data == '/'){
        return 2;
    }
    else{
        return 1;
    }
}

char peek(struct Stack * s1){
    return s1->arr[s1->top];   
}

char pop(struct Stack *s1){
    char temp = s1->arr[s1->top];
    s1->top  =s1->top-1;
    return temp;
}

int main(){
struct Stack * s1 = (struct Stack*)malloc(sizeof(struct Stack));
init(s1);
char expression[] = "a+b*c";
int counter =0;
while (expression[counter] != '\0')
{
    if(!isOperator(expression[counter])){
        printf("%c",expression[counter]);
        counter++;
    }
    else{
        if(isEmpty(s1)){
                push(s1,expression[counter]);
                counter++;
        }
        else if(precedence(expression[counter]) > precedence(peek(s1))){
            push(s1,expression[counter]);
            counter++;
        }
        else{
                while (!isEmpty(s1) || precedence(expression[counter]) > precedence(peek(s1)))
                {
                    printf("%c",pop(s1));
                }    
             
        }
    }

}


while (!isEmpty(s1))
{
    printf("%c",pop(s1));
}


 
return 0;
}