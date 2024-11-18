// #include<stdio.h>
// #include<stdlib.h>
// #define MAX 5
// int main(){
// int adjmatix[MAX][MAX] = {
//     {0,0,0,0,1}, //0
//     {0,0,1,0,0}, //1
//     {0,0,0,1,0}, // 2
//     {0,0,0,0,0}, // 3
//     {0,1,0,0,0}, //4
// }; 
// int queue[MAX] = {0};
// int visited[MAX] = {0};
// int rear = 0;
// int front = 0;
// int starting  = 0;
// queue[rear++] = starting;
// visited[starting] = 1;
// while (front < rear)
// {
//     int current = queue[front++];
//     printf("%d",current);
//     for (int i = 0; i < MAX; i++)
//     {
//         if(adjmatix[current][i] == 1 && visited[i] == 0){
//             queue[rear++] = i;
//         }
//     }
    
// }



// return 0;
// }


#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int main(){

int ajmatrix[MAX][MAX]  = {
    {0,0,0,0,1},
    {0,0,1,0,0},
    {0,0,0,1,0},
    {0,0,0,0,0},
    {0,1,0,0,0}
};
int queue[MAX] = {0};
int visited[MAX] = {0};
int rear = 0;
int front = 0;
int starting  =0;
queue[rear++] = starting;
while (front <rear)
{
    int current = queue[front++];
    printf("%d",current);
    for (int i = 0; i < MAX; i++)
    {
        if(ajmatrix[current][i] == 1 && visited[i] == 0){
            queue[rear++] = i;
        }
    }

    
}

 
 
return 0;
}