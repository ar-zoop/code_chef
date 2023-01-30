//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    void dfs(int node, vector<int> adj[], stack<int>&stk, int vis[]){
        vis[node]=1;
        int N=adj[node].size();
        for(int i=0; i<N; i++){
            if(!vis[adj[node][i]]){
                dfs(adj[node][i], adj, stk, vis);
            }
        }
        stk.push(node);
            
    }
    vector<int> findOrder(int n, int m, vector<vector<int>> pre) 
    {
        //code here
        vector<int> adj[n];
        queue<int>que;
        vector<int>res;
        int indegree[n]={0};
        for(int i=0; i<m; i++){
            adj[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }
       
        for(int i=0; i<n; i++){
            if(indegree[i]==0) que.push(i);
        }
        int front;
        while(!que.empty()){
            front=que.front();
            que.pop();
            res.push_back(front);
            for(int i=0; i<adj[front].size(); i++){
                indegree[adj[front][i]]--;
                if(indegree[adj[front][i]]==0) que.push(adj[front][i]);
            }
        }
        if(res.size()==n)     return res;
        return {};
    }
};

//{ Driver Code Starts.

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> prerequisites;

        for (int i = 0; i < m; i++) {
            cin >> u >> v;
            prerequisites.push_back({u,v});
        }
        
        vector<int> adj[n];
        for (auto pre : prerequisites)
            adj[pre[1]].push_back(pre[0]);
        
        Solution obj;
        vector <int> res = obj.findOrder(n, m, prerequisites);
        if(!res.size())
            cout<<"No Ordering Possible"<<endl;
        else
            cout << check(n, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends