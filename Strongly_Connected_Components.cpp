//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:

	void dfs(int node, vector<vector<int>>& adj, int vis[], stack<int> &finTime){
	    vis[node]=1;
	    for(auto adjNode:adj[node]){
	        if(!vis[adjNode]){
	            dfs(adjNode, adj, vis, finTime);
	        }
	    }
	   finTime.push(node);
	}
	void dfs(int node, vector<vector<int>>& adj, int vis[]){
	    vis[node]=1;
	    for(auto adjNode:adj[node]){
	        if(!vis[adjNode]){
	            dfs(adjNode, adj, vis);
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        int vis[V]={0};
        stack<int> finTime;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, finTime);
            }
        }
        vector<vector<int>> revAdj(V);
        int node;
        for(int i=0; i<V; i++){
            for(auto j: adj[i]){
                revAdj[j].push_back(i);
            }
        }
        int dfsVis[V]={0};
        int count=0;
        while(!finTime.empty()){
            node=finTime.top();
            finTime.pop();
            if(!dfsVis[node]){
                count++;
                dfs(node,revAdj,dfsVis);
                
            }
        }
        return count;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends