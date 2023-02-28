//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        queue<pair<int,pair<int,int>>> q;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> shortestDist(n,vector<int>(m, 1e9));
        int delR[4]={+1,0,-1,0};
        int delC[4]={0,+1,0,-1};
        q.push({0,{0,0}});
        shortestDist[0][0]={0};
        int row,col,dist, newR, newC;
        while(!q.empty()){
            dist=q.front().first;
            row=q.front().second.first;
            col=q.front().second.second;
            q.pop();
            int parent=shortestDist[row][col];
            for(int i=0; i<4; i++){
                newR=row+delR[i];
                newC=col+delC[i];
                if(newC >=0 && newC<m && newR>=0 && newR<n){
                    int curr=shortestDist[newR][newC];
                    int c=abs(heights[newR][newC]-heights[row][col]);
                    int calc= max(parent, c);
                    if(curr>calc){
                        shortestDist[newR][newC]=calc;
                        q.push({shortestDist[newR][newC], {newR, newC}});
                    }
                }
            }
        }
        return shortestDist[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends