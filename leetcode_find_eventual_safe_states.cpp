class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>&localVis,vector<int>&globalVis, vector<int>&checked){
        localVis[node]=1;
        globalVis[node]=1;
        int N=adj[node].size();
        for(int i=0; i<N; i++){
            if(!globalVis[adj[node][i]]){
                if(dfs(adj[node][i], adj, localVis, globalVis, checked)){
                    checked[node]=0;
                    return true;
                }
            }
            else if(localVis[adj[node][i]]){
                checked[node]=0;
                return true;               
            } 
        }
        checked[node]=1;
        localVis[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N=graph.size();
        vector<int>localVis(N,0);
        vector<int>globalVis(N,0);
        vector<int>checked(N,0);
        for(int i=0; i<N; i++){
            if(!globalVis[i]){
                dfs(i,graph,localVis, globalVis, checked);
            }
        }
        vector<int>res;
        for(int i=0; i<N; i++){
            if(checked[i]==1){
                res.push_back(i);
            }
        }
        return res;
    }
};