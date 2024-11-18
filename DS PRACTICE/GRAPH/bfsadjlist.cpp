#include<iostream>
#include<vector>
#define MAX 5
using namespace std;
struct Node{
    struct Node * next;
    int data;
};
vector<struct Node *> s1;

struct Node * newnode(int data){
    struct Node * s1 = (struct Node*)malloc(sizeof(struct Node));
    s1->data = data;
    s1->next = NULL;
    return s1;
}
void addEdge(int vertex,int edge){
    s1[vertex]->next = newnode(edge);
}


void init(int arr[5]){
    for (int i = 0; i < 5; i++)
    {
        s1.push_back(newnode(i)); 
    }
    
}

void bfs(int starting){
    int queue[MAX] = {0};
    int visited[MAX] = {0};
    int front  = 0;
    int rear = 0;
    queue[rear++] = starting;
    visited[starting] = 1;
    while (front<rear)
    {
        int current = queue[front++];
        struct Node * temp = s1[current];
        while (temp!=NULL)
        {
            if(visited[temp->data] == 0){
                printf("%d",temp->data);
                queue[rear++] = temp->data; 
                visited[temp->data] = 1;
            }
            temp = temp->next;
        }

    }
    


}
int main(){
    int arr[] = {0,1,2,3,4};
    init(arr);
addEdge(0,4);
addEdge(4,1);
addEdge(1,2);
addEdge(2,3);
bfs(0);


 
return 0;
}