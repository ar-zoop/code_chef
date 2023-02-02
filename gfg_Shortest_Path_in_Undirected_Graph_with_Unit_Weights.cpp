//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void bfs(int src, vector<int>adj[],vector<int>&path){
        queue<pair<int,int>>que;
        que.push({src,0});
        pair<int,int>front;
        int node, weight;
        while(!que.empty()){
            front=que.front();
            que.pop();
            node=front.first;
            weight=front.second;
            if(path[node]!=0)
                path[node]=min(path[node],weight);
            else
                path[node]=weight;
            for(int i=0; i<adj[node].size(); i++){
                if(!path[adj[node][i]])
                    que.push({adj[node][i], weight+1});
            }
        }
    }
    void createAdjList(vector<int>adj[], vector<vector<int>>& edges, int M){
        for(int i=0; i<M; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
    }
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int>adj[N];
        vector<int>path(N,0);
        createAdjList(adj,edges,M);
        bfs(src, adj, path);
        for(int i=0; i<N; i++){
            if(path[i]==0 && i!=src){
                path[i]=-1;
            }
        }
        path[src]=0;
        return path;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends