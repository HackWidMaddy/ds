#include<stdio.h>
#include<stdlib.h>
struct Stack{
    int *arr;
    int top;
    int size;
};

void init(struct Stack * s1){
    s1->size = 10;
    s1->arr=(int *)malloc(sizeof(int) * s1->size);
    s1->top = -1;
}

int isOperator(char data){
    if(data == '+' || data == '-' || data == '*' || data == '/'){
        return 1;
    }
    return 0;
}

void push(struct Stack * s1,int data){
    s1->top = s1->top+1;
    s1->arr[s1->top] = data;
}

int pop(struct Stack *s1){
    int data = s1->arr[s1->top];
    s1->top = s1->top-1;
    return data;
}

//  printf("%d",a - 48);
int main(){
    struct Stack * s1 = (struct Stack *)malloc(sizeof(struct Stack));
    init(s1);
    char expression[] = "234*5*-";
    int counter = 0;
    while (expression[counter]!='\0')
    {
        if(!isOperator(expression[counter])){
            push(s1,expression[counter] - 48);
            counter++;
        }
        else{
            int right = pop(s1);
            int left = pop(s1);
            switch (expression[counter])
            {
            case '+':
                push(s1,left+right);
                break;
            case '-':
                push(s1,left-right);
                break;
            case '*':
                push(s1,left*right);
                break;
            case '/':
                push(s1,left/right);
                break;
            }

            counter++;
        }
    }
    
printf("%d",pop(s1));

return 0;
}