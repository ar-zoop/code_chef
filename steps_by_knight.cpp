//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool isValid(int x, int y, int N){
        if(x>=0 && y>=0 && x<N && y<N) return true;
        return false;
    }
    int bfs(int i, int j, int level, int ti, int tj, int  N){
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> vis(N,vector<int>(N,0));
        q.push({0,{i,j}});
        vis[i][j]=0;
        int x,y;
        int deli[]={-2, -2, -1, +1, +2, +2, -1, +1};
        int delj[]={-1, +1, +2, +2, +1, -1, -2, -2};
        while(!q.empty()){
            level=q.front().first;
            i=q.front().second.first;
            j=q.front().second.second;
            
            q.pop();
            if(i==ti && j==tj) return level;
            
            for(int a=0; a<8; a++){
                x=i+deli[a];
                y=j+delj[a];
                if(isValid(x,y,N) && !vis[x][y]){
                    vis[x][y]=1;
                    q.push({level+1,{x,y}});
                }
            }
        }
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    return bfs(KnightPos[0]-1, KnightPos[1]-1, 0, TargetPos[0]-1, TargetPos[1]-1, N);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends