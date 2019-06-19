#include <bits/stdc++.h>
#define white 1 
#define gray 2 
#define black 3

using namespace std;
int node,edge;
int adj[100][100];
int color[100];
int scc = 0 ; //strongly connected components

int Time = 1 ;
int starting_time[100];
int finishing_time[100];
stack<int>ans;

void bfsvisit(int starting_node)
{
    color[starting_node] = gray;
    starting_time[starting_node] = Time;
    Time++;
    for(int i = 0 ;i<node; i++)
    {
        if(adj[starting_node][i]==1)
        {
            if(color[i]==white)
            {
                bfsvisit(i);
            }
        }
    }
    color[starting_node] = black;
    finishing_time[starting_node] = Time;
    Time++;
    ans.push(starting_node);
}

void bfs()
{
    for(int i = 0 ;i<node;i++)
    {
        color[i] = white ;
    }
    for(int i = 0;i<node ;i++)
    {   
        if(color[i]==white)
        {
            scc++;
            bfsvisit(i);
        }
    }
}

void graph(int node , int edge)
{
    int n1,n2;
    for(int i = 0 ;i<edge;i++)
    {
        cin>>n1>>n2;
        adj[n1][n2] = 1 ;
        //adj[n2][n1] = 1 ;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    cin>>node>>edge;
    graph(node,edge);
    bfs();
    cout<<"strongly connected component: ";
    cout<<scc<<endl;
    for(int i = 0 ;i<node;i++)
    {
        cout<<"Node no : "<<i<<" starting time "<<starting_time[i]<<" Finishing time "<<finishing_time[i]<<endl;
    }
    while(!ans.empty())
    {
        cout<<ans.top()<<endl;
        ans.pop();
    }

    return 0 ;
}