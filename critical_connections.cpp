//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    void dfs(int node, int parent, vector<int>&tin, vector<int>&low, vector<int>&vis, vector<vector<int>>&bridges, vector<int> adj[]){
        vis[node]=1;
        for(auto adjNode: adj[node]){
            if(!vis[adjNode]){
                // cout<<"hey";
                tin[adjNode]=tin[node]+1;
                low[adjNode]=tin[node]+1;
                dfs(adjNode, node, tin, low, vis, bridges, adj);
            }
        }
        for(auto adjNode:adj[node]){
            if(adjNode!=parent && low[node]>low[adjNode]){
                low[node]=low[adjNode];
            }
        }
        if(tin[node]>low[parent] && low[node]>tin[parent]){
            vector<int>edge;
            edge.push_back(min(node,parent));
            edge.push_back(max(node,parent));
            bridges.push_back(edge);
        }
        // return;
    }
    
	vector<vector<int>>criticalConnections(int V, vector<int> adj[]){
	    // Code here
	    vector <vector<int>> bridges;
	    vector <int> tin(V), low(V), vis(V,0);
	    tin[0]=0;
	    low[0]=0;
	    dfs(0, -1, tin, low, vis, bridges, adj);
	    sort(bridges.begin(), bridges.end());
	    return bridges;
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
        vector<vector<int>>ans = obj.criticalConnections(V, adj);
        
        for(int i=0;i<ans.size();i++)
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
    }
	return 0;
}
// } Driver Code Ends