#include<stdio.h>
#include<stdlib.h>
struct Stack{
    char *arr;
    int top;
    int size;
};

void init(struct Stack *s1){
    s1->top = -1;
    s1->size = 10;
    s1->arr= (char *)malloc(sizeof(char)* s1->size);
}
void pushChar(struct Stack *s2,char data){
    s2->top = s2->top + 1;
    s2->arr[s2->top] = data;
}
char popsymbol(struct Stack *s2){
    char temp = s2->arr[s2->top];
    s2->top = s2->top - 1;
    return temp;
}

int isbracket(char data){
    if(data == '{' || data == '}' || data == '(' || data == ')' || data == '[' || data == ']'){
        return 1;
    }
    return 0;
}

int isOpen(char data){
    if(data=='('  || data=='['  || data=='{' ){
        return 1;
    }
    return 0;
}


int check(char open,char close){
    if(open == '(' && close==')'){
        return 1;
    }
    else if(open == '[' && close==']'){
        return 1;
    }
    else if(open == '{' && close=='}'){
        return 1;
    }
    return 0;
}
int main(){
    struct Stack *s1 = (struct Stack*)malloc(sizeof(struct Stack));
    init(s1);
    int balance  = 0;
    char expression[] = "a{b[c(d+e)/2-f]+1}";
    int counter = 0;
    while (expression[counter]!= '\0')
    {
        if(isbracket(expression[counter])){

            if(isOpen(expression[counter])){
                    pushChar(s1,expression[counter]);
            }
            else{
                char temp = popsymbol(s1);
                if(!check(temp,expression[counter])){
                    balance = 0;
                    break;
                }
                else{
                    balance = 1;
                }
            }


        }


        counter++;
    
    }   

if(s1->top != -1) {
    balance = 0;
}
printf("%d",balance); 
return 0;
}