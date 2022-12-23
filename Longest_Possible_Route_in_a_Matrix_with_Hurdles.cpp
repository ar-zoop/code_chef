//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
   
    
    int dfs(int i, int j, vector<vector<int>> &matrix, int n, int m, int xs, int ys, int xd, int yd){
        if(i==xd && j==yd) {
            return 0;
        }
        if(i<0 || j<0 || i>=n || j>=m) return INT_MIN;
        if(matrix[i][j]!=1) return INT_MIN;
        // int up,down=INT_MIN,left=INT_MI N,right=INT_MIN;
        if(i>=0 && i<n && j>=0 && j<m && matrix[i][j]==1){
            // if(memo[i][j]!=-1) return memo[i][j];
            matrix[i][j]=-1;
            int down=dfs(i+1,j,matrix,n,m,xs,ys,xd,yd) +1;
            int up=dfs(i-1,j,matrix,n,m,xs,ys,xd,yd) +1;
            int right=dfs(i,j+1,matrix,n,m,xs,ys,xd,yd) +1;
            int left=dfs(i,j-1,matrix,n,m,xs,ys,xd,yd)+1;
            matrix[i][j]=1;
            return max({up,down,right,left});
        }
        // return INT_MIN;
        // return 0;
        
    }
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        int n=matrix.size(), m=matrix[0].size();
        // vector<vector<int>>memo(n,vector<int>(m,-1));
        if(matrix[xs][ys]!=1 || matrix[xd][yd]!=1 ) return -1;
        int ans=dfs(xs,ys,matrix, n, m, xs,ys,xd,yd);
        if (ans<=0 )return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends