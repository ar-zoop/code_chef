#include <bits/stdc++.h> 
using namespace std;

// void dfs(int node, int child, int grandchild, vector<int> adjList[], vector<int> &vis, vector<int> &count){
	
// 	vis[node]=1;
// 	for(auto adjNode: adjList[node]){
// 		if(adjNode==grandchild) count.push_back(adjNode);
		
// 		if(!vis[adjNode]){
// 			dfs(adjNode, node, child, adjList, vis, count);
// 		}
// 	}
	
// }

void dfs(int node, int parent, int depth, vector<int> adjList[], vector<int> &vis, int &count) {
    vis[node] = 1;
    for (int adjNode : adjList[node]) {
        if (adjNode == parent) continue;
        if (vis[adjNode]) {
            // Check for triangle
            for (int k : adjList[adjNode]) {
                if (k == node) {
                    count++;
                    break;
                }
            }
        } else {
            dfs(adjNode, node, depth+1, adjList, vis, count);
        }
    }
    vis[node] = 0;  // Unmark visited node
}


vector<int> countTriangles(int V1, vector<vector<int>>& edgeListOfDirectedGraph, int V2,
vector<vector<int>>& edgeListOfUnDirectedGraph) {
	vector<int> res;
	// vector<int>count1, count2;
	vector<int>vis;
	int count=0;
	vector<int> adjList[V1], adjList2[V2];
	for(int i=0; i<edgeListOfDirectedGraph.size(); i++){
		int a=edgeListOfDirectedGraph[i][0];
		int b=edgeListOfDirectedGraph[i][1];
		adjList[a].push_back(b);
	}
	vis.resize(V1 , 0);
	for(int i=0; i<V1; i++){
		dfs(i,-1, 0, adjList, vis, count);
	}
	res.push_back(count);
	count=0;
	vis.resize(V2 , 0);
	for(int i=0; i<edgeListOfUnDirectedGraph.size(); i++){
		int a=edgeListOfUnDirectedGraph[i][0];
		int b=edgeListOfUnDirectedGraph[i][1];
		adjList2[a].push_back(b);
		adjList2[b].push_back(a);
	}
	dfs(0, -1, 0, adjList2, vis, count);
	res.push_back(count);
	return res;
}