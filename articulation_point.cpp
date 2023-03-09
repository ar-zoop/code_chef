//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int timer=0;
    void dfs(int node, int parent, vector<int>&low, vector<int>&tin, vector<int>&vis,  vector<int>&mpp, vector<int>adj[]){
        vis[node]=1;
        tin[node]=timer;
        low[node]=timer;
        timer++;
        int child=0;
        for(auto adjNode: adj[node]){
            if(!vis[adjNode] && adjNode !=parent){
                dfs(adjNode, node, low, tin, vis, mpp, adj);
                // vis[adjNode]=0;
                low[node]=min(low[node], low[adjNode]);
                //backtracking
                if(low[adjNode] >= tin[node] && parent!=-1){
                    mpp[node]=1;
                }
                child++;
            }
            else if(adjNode !=parent){
                low[node]=min(low[node], tin[adjNode]);
            }
        }
        if(parent==-1 && child>1) mpp[node]=1;
        // vis[node]=0;
        return;
    }
    
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> vis(V,0), low(V), tin(V), res(V,0), mark;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, -1, low, tin, vis, res, adj);
            }
        }
    
        for(int i=0; i<V; i++){
            if(res[i]) mark.push_back(i);
        }
        if(mark.size()==0) return {-1};
        return mark;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends