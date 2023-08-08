#include <bits/stdc++.h>

using namespace std;

//find augmenting path to reach to source
bool bfs(int rgraph[6][6], int s, int t, int parent[6]){
    
	int n = 6, u;
	int visited[n] = {0};
    
    
	queue<int> q;
	q.push(s);
	visited[s] = 1;
	parent[s] = -1;
    
	while(!q.empty()){
    	u = q.front();
    	q.pop();
    	for(int v=0; v<n; v++){
        	if(visited[v] == 0 && rgraph[u][v] > 0){
            	if(v == t){
                	parent[v] = u;
                	return true;
            	}
           	 
            	q.push(v);
            	parent[v] = u;
            	visited[v]= 1;
        	}
    	}
	}
	return false;
}

int fordfulkarson(int g[6][6], int s, int t){
    
	int rgraph[6][6];
    
	for(int u=0; u<6; u++){
    	for(int v=0; v<6; v++){
        	rgraph[u][v] = g[u][v];
    	}
	}


	int parent[6], max_flow = 0;
	int path_flow, u;
    
	while(bfs(rgraph,s,t,parent))
	{
    	path_flow = INT_MAX;

		//find bottlenack  capacity
    	for(int v=t; v!=s; v = parent[v]){
        	u = parent[v];
        	path_flow = min(path_flow,rgraph[u][v]);
    	}
   	 
	 	//forward shows remaining flow and reverse shows actual flow we had passsed
    	for(int v=t; v!=s; v=parent[v]){
        	u = parent[v];
        	rgraph[u][v] -= path_flow;
        	rgraph[v][u] += path_flow;
    	}
   	 
	 	//add with bottle neck of eveery path to get maxflow
    	max_flow += path_flow;
	}
	return max_flow;
}

int main()
{
	int Graph[6][6] = {
    	{0,16,13,0,0,0},
    	{0,0,10,12,0,0},
    	{0,4,0,0,14,0},
    	{0,0,9,0,0,20},
    	{0,0,0,7,0,4},
    	{0,0,0,0,0,0},
   	 
	};
    
    
	int ans = fordfulkarson(Graph,0,5);
    
	cout << “Max Flow is :” << ans;
    
	return 0;
}

