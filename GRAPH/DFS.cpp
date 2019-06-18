#include<bits/stdc++.h>
#define white 1
#define gray 2
#define black 3

using namespace std;
int adj[100][100];
int color[100];
int node,edge;
int scc = 0 ; //strong ly connected component

void dfsvisite(int x)
{
    color[x]=gray;
    cout<<x<<" is gray "<<endl;
    for(int i = 0 ;i<node;i++)
    {
        cout<<"adj[x][i] "<<x<<" "<<i<<" "<<adj[x][i]<<" color is: "<<color[i]<<endl;
        if(adj[x][i]==1)
        {
            if(color[i]==white)
            {
                dfsvisite(i);
            }
        }
    }
    color[x]=black;
    cout<<x<<" is black "<<endl;
}
void dfs()
{
    for(int i = 0 ;i<node;i++)
    {
        color[i]=white;
    }
    for(int i = 0 ;i<node; i++)
    {
        cout<<"DFS push node "<<i<<endl;
        if(color[i]==white)
        {
            cout<<"Node  : "<<i<<" is white"<<endl;
            scc++;
            dfsvisite(i);
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    scanf("%d %d",&node,&edge);

    int n1,n2;
    for(int i= 0 ;i<edge;i++)
    {
        scanf("%d %d",&n1,&n2);
        adj[n1][n2]=1;
        adj[n2][n1]=1;
    }
    dfs();
    cout<<scc<<endl; //Strongly connected component 
    return 0 ;
}


/*
Input:

7 7
0 1
0 2
1 2
1 3
1 4
3 4
5 6

 */