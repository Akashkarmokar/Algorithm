#include<bits/stdc++.h>
using namespace std;

#define Max 10001
int arr[Max],tree[4*Max];

void init(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return ;
    }
    int left = node*2;
    int right = left + 1 ;    // node*2 + 1;
    int mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j) // i=search query begining , j= search query ending
{
    if(i>e || j<b)
    {
        return 0; // out of range
    }
    if(i<=b && j>=e)  //relevant segment
    { 
        return tree[node];
    }
    int left = node*2;
    int right = left + 1; //node*2 + 1;
    int mid = (b+e)/2;
    int p1 = query(left,b,mid,i,j);
    int p2 = query(right,mid+1,e,i,j);
    return p1+p2;
}

void update (int node,int b,int e,int i,int newValue)
{
    if(i<b || i>e)
    {
        return ; // out of range
    }
    if(i>=b && e<=i)
    {
        tree[node] =newValue;
        return ;
    }
    int left = node*2;
    int right = left + 1; // node*2 + 1;
    int mid = (b+e)/2;
    update(left,b,mid,i,newValue);
    update(right,mid+1,e,i,newValue);
    tree[node]=tree[left]+tree[right];
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    init(1,1,n);
    cout<<query(1,1,n,1,n)<<endl;
    update(1,1,n,4,0);
    cout<<query(1,1,n,1,n)<<endl;
    return 0;
}