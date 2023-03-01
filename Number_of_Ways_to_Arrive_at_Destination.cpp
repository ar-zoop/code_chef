//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#include <cmath>
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        //part 1: finding out the shortest dist to reach the dest || DIJKSTRAS
        priority_queue<pair<long long ,long long >, vector<pair<long long ,long long >>, greater<pair<long long ,long long >>>pq;
        pq.push({0,0});
        vector<long long>shortestDist(n,1e18);
        long long nodeWt, node, adjNode, adjWt;
        vector<pair<long long ,long long >>adj[n];
        
        //create adj list
        for(auto vec: roads){
            adj[vec[0]].push_back({vec[1], vec[2]});
            adj[vec[1]].push_back({vec[0], vec[2]});
        }
        
        while(!pq.empty()){
            nodeWt=pq.top().first;
            node=pq.top().second;
            pq.pop();
            for(auto it: adj[node]){
                adjNode=it.first;
                adjWt=it.second;
                if(shortestDist[adjNode]>nodeWt+adjWt){
                    shortestDist[adjNode]=nodeWt+adjWt;
                    pq.push({nodeWt+adjWt, adjNode});
                }
            }
        }
        
        long long minWt=shortestDist[n-1];
        double count=0, mod=1e9+7;
        // cout<<"minWt="<<minWt<<endl;
        // part 2: finding paths which hit target minWt ||  DIJKSTRAS
        queue<pair<long long ,long long >> q;
        vector<long long >vis(n,0);
        q.push({0,0});
        while(!q.empty()){
            nodeWt=q.front().second;
            node=q.front().first;
            if(node!=n-1) vis[node]=1;
            q.pop();
            for(auto it: adj[node]){
                adjWt=it.second;
                adjNode=it.first;
                if(!vis[adjNode]){
                    // cout<<adjNode<<" " << adjWt+nodeWt<<endl;
                    if(adjNode==n-1 && adjWt+nodeWt==minWt){
                        count++;
                        count=fmod(count,mod);
                    }
                    else if(adjWt+nodeWt<minWt){
                        long long wt=adjWt+nodeWt;
                        q.push({adjNode, wt});                
                    }
                }
            }
        }
        
        
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends