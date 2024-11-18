#include<stdio.h>
#include<stdlib.h>
int arr[10] ;
// size = 10 || key = 11
void insert(int data){
    int mode = data%11;
    int placementindex;

    for (int i = 0; i < 10; i++)
    {
        placementindex = (mode + i)%10;
        if(arr[placementindex] != 0){
            continue;
        }else{
            arr[placementindex] = data;
            break;

        }
    }
    
    
}

int main(){
 
//  h(k,i) = (h1(k) + i) mod m

// 12,34
insert(12);
insert(34);
insert(45);


for (int i = 0; i < 10; i++)
{
printf("%d ",arr[i]);    
}


return 0;
}