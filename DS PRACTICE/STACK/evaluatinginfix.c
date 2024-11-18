#include<stdio.h>
#include<stdlib.h>
struct NumberStack{
    int *arr;
    int top;
    int size;
};

struct SymbolStack{
    char *arr;
    int top;
    int size;
};
void init(struct NumberStack *s1,struct SymbolStack *s2){
    s1->top = -1;
    s1->size = 10;
    s1->arr= (int *)malloc(sizeof(int)* s1->size);

    s2->top = -1;
    s2->size = 10;
    s2->arr= (char *)malloc(sizeof(char)* s2->size);

}

int isOperator(char data){
    if(data == '+' ||data == '/' ||data == '-' ||data == '*' ||data == '^'){
        return 1;
    }
    else{
        return 0;
    }
}

void pushNumber(struct NumberStack *s1,int data){
    s1->top = s1->top + 1;
    s1->arr[s1->top] = data;
}


void pushChar(struct SymbolStack *s2,char data){
    s2->top = s2->top + 1;
    s2->arr[s2->top] = data;
}

int isEmpty(struct SymbolStack *s1){
    if(s1->top==-1){
        return 1;
    }
    return 0;
}


int popnumber(struct NumberStack *s1){
    int temp = s1->arr[s1->top];
    s1->top = s1->top -1;
    return temp;
}


char popsymbol(struct SymbolStack *s2){
    char temp = s2->arr[s2->top];
    s2->top = s2->top - 1;
    return temp;
}
int main(){
    struct NumberStack *s1 = (struct NumberStack*)malloc(sizeof(struct NumberStack));
    struct SymbolStack *s2 = (struct SymbolStack*)malloc(sizeof(struct SymbolStack));
    char expression[] = "2+3*4";
    init(s1,s2);
    int counter = 0;
    while (expression[counter] != '\0')
    {
        if(isOperator(expression[counter])){
            pushChar(s2,expression[counter]);
        }
        else{
            int temp = expression[counter] - '0';
            pushNumber(s1,temp);
        }

        counter++;
    }


    while (!isEmpty(s2))
    {
        int right = popnumber(s1);
        int left= popnumber(s1);
        char symbole = popsymbol(s2);
        switch (symbole)
        {
        case '+':
            pushNumber(s1,left+right);
            break;
        case '-':
            pushNumber(s1,left-right);
            break;
        case '*':
            pushNumber(s1,left*right);
            break;
        case '/':
            pushNumber(s1,left/right);
            break;

        }

    }

    printf("Result: %d\n", s1->arr[s1->top]);  // Print the result
    
 
return 0;
}