#include<stdio.h>
#include<stdbool.h>  //It is used for boolean type datatype 

#define size 100
// #define WHITE 1
// #define GRAT 2
// #define BLACK 3

int queue[size];
int adj[size][size];
//int color[100];
int distance[100];
bool visited[100];
int parent[100];

int node,edges,front=0,rare=0;

//Pushing function in queue :
void enqueue(int value){
    if(rare==size){
        printf("Your queue is full.You can't enqueue any number.\n");
    }
    else{
        queue[rare]=value;
        rare++;
    }
}
//Print function of the queue :
void display(){
    if(front==rare){
        printf("Queue is empty\n");
    }
    else{
        int t;
        printf("Queue is:");
        for(t=front;t<rare;t++){
            printf("%d ",queue[t]);
        }
        printf("\n");
    }
}
// POPing function of the queue :
void dequeue(){
    if(front==rare){
        printf("Your Queue is empty (I am in dequeue function)\n");
    }
    else {
        front++;
    }
}
void graph(int edges){
    int node1,node2,i;
    for(i=0;i<edges;i++){
        scanf("%d %d",&node1,&node2);
        adj[node1][node2]=1;
        adj[node2][node1]=1;
    }
    printf("Adjacency Matrix:\n");
    int j;
    printf("\n");
    for(i=0;i<node;i++){
        for(j=0;j<node;j++){
            printf("%d |",adj[i][j]);
        }
        printf("\n_______________________\n");
    }
}
void BFS(int source_node){
    enqueue(source_node);
    distance[source_node]=0;
    visited[source_node]=1;
    parent[source_node]=-1;
   // int temp=rare;
    while(1){
        int u = queue[front];
        dequeue();
        int i;
        for(i=0;i<node;i++){
            if(adj[u][i]==1 && visited[i]==0){
                enqueue(i);
                visited[i]=1;
                parent[i]=u;
                distance[i]=distance[u]+1;
            }
        }
        if(rare==front){
            break;
        }
    }
    int x;
    printf("\n-----------------------Minimum distances--------------------------\n");
    for(x=0;x<node;x++){
        printf("Minimum distance from %d to %d is: %d\n",source_node,x,distance[x]);
    }
    printf("\n-------------------------Parents Node------------------------------\n");
    for(x=0;x<node;x++){
        if(parent[x]<0){
            printf("That(%d) is is the source node.It has no parent node\n",x);
        }
        else{
            printf("Parent node of %d is: %d\n",x,parent[x]);
        }
    }
}
int main(){
    /*
    printf("Enter the no of NODES:");
    scanf("%d",&node);
    printf("Enter the no of edges:");
    scanf("%d",&edges);
    int n1,n2,i;
    for(i=0;i<edges;i++){
        scanf("%d %d",&n1,&n2);
        adj[n1][n2]=1;
        adj[n2][n1]=1;
    }
    
    int j;
    printf("\n");
    for(i=0;i<node;i++){
        for(j=0;j<node;j++){
            printf("%d |",adj[i][j]);
        }
        printf("\n_______________________\n");
    }
    */
    int source_node;
    printf("Enter the no of node:");
    scanf("%d",&node);
    printf("Enter the no of edges:");
    scanf("%d",&edges);
    graph(edges);
    printf("Enter the source node:");
    scanf("%d",&source_node);
    BFS(source_node);
    return 0;

}

// input :
// 8 7(node edges)
/*
0 1
0 2
1 3
2 4
2 5
3 6
3 7
*/

// Created By: Akash karmokar
//             Metropolitan University,Sylhet,Bangladesh.
//             Dept: Computer science and engineering .
//             Batch:38th .