#include<iostream>
#include<stdbool.h>
#include<vector>
#include<queue>
using namespace std;
int node;
int dist[5];
bool visited[5];
vector<int>list[5];

void adj_list(int node,int edge){
	//vector<int>list[node];
	int n1,n2;
	for(int i = 1;i<= edge;i++){
		scanf("%d %d",&n1,&n2);
		list[n1].push_back(n2);
		list[n2].push_back(n1);
	}
	for(int i = 0;i< node;i++){
		printf("index %d:",i);
		for(int j = 0;j<list[i].size();j++){
			printf("%d ",list[i][j]);
		}
		printf("\n");
	}
}
void bfs(int node,int edge,int source){
	queue<int>Q;
	Q.push(source);
	visited[source] = 1 ;
	dist[source] = 0 ;
	while(!Q.empty()){
		int u = Q.front();
		Q.pop();
		for(int i = 0;i<list[u].size();i++){
			int x = list[u][i];
			//Q.push(x);
			if(visited[x]==0){
				Q.push(x);
				visited[x]=1;
				dist[x] = dist[u]+1;
			}
		}
	}
	for(int i =0;i<node;i++){
		printf("Minimum distance from %d to %d is: %d\n",source,i,dist[i]);
	}
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	
	int edge,source;
	scanf("%d %d %d",&node,&edge,&source);

	adj_list(node,edge);
	bfs(node,edge,source);
	return 0;
}
