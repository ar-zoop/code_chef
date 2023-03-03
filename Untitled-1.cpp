//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int dt){
        vector<vector<int>> cost (n, vector<int>(n,1e9));
        for(int i=0; i<n; i++){
            cost[i][i]=0;
        }
        
        for(auto vec: edges){
            cost[vec[0]][vec[1]]=vec[2];
            cost[vec[1]][vec[0]]=vec[2];
        }
        
        for(int via=0; via<n; via++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    cost[i][j]=min(cost[i][j], cost[i][via]+cost[via][j]);
                }
            }
        }
        
        int minRes=INT_MAX, res=0, city;
        
        for(int i=0; i<n; i++){
            res=0;
            for(int j=0; j<n; j++){
                if(cost[i][j]<=dt){
                    res++;
                }
            }
            // cout<<res;
            if(res<=minRes) {
                minRes=res;
                city=i;
            }
            // cout<<city;
        }
        return city;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends