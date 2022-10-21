class Solution {
    vector<bool> vis;
    vector<int> res;
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int i, vector<int> adj[]){
        res.push_back(i);
        vis[i]=true;
        for(auto x:adj[i]){
            if(!vis[x]){
                dfs(x,adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vis.resize(V, 0);
        for(int i=0; i<V;i++){
            if(!vis[i]){
                dfs(i, adj);
            }
        }
        return res;
    }
};