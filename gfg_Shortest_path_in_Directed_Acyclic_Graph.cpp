//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void dfs(int node ,stack<int>&topo, vector<pair<int,int>>adj[], int vis[]){
        vis[node]=1;
        for(int i=0; i<adj[node].size(); i++){
            if(!vis[adj[node][i].first]){
                dfs(adj[node][i].first, topo, adj, vis);
            }
        }
        topo.push(node);
    }
    
    void topoSort(stack<int>&topo, vector<pair<int,int>>adj[], int N){
        int vis[N]={0};
        for(int i=0; i<N; i++){
            if(!vis[i])dfs(i,topo,adj,vis);
        }
    }
    
    void relaxation(stack<int>&topo, vector<pair<int,int>>adj[], vector<int>&shortestPath, int src){
        shortestPath[src]=0;
        int top;
        long long int weight;
        int neighbourWeight;
        while(!topo.empty()){
            top=topo.top();
            weight=shortestPath[top];
            topo.pop();
            if(weight==INT_MAX) continue;
            for(int i=0; i<adj[top].size(); i++){
                neighbourWeight=adj[top][i].second;
                neighbourWeight+=weight;
                shortestPath[adj[top][i].first]=min(neighbourWeight, shortestPath[adj[top][i].first]);
            }
        }
    }
    
    void createAdjList(vector<vector<int>>& edges,vector<pair<int,int>>adj[],int numNodes, int edgeLength){
        for(int i=0; i<edgeLength; i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
    }
    
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>>adj[N];
        createAdjList(edges,adj,N,M);
        stack<int>topo;
        topoSort(topo,adj, N);
        vector<int>shortestPath(N, INT_MAX);
        relaxation(topo,adj,shortestPath, 0);
        for(int i=0; i<N; i++){
            if(shortestPath[i]==INT_MAX) shortestPath[i]=-1;
        }
        return shortestPath;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends