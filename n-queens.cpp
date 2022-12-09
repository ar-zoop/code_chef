//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool isValid(int row, int col, int n,  vector<int>&top, vector<int>&left_diagonal, vector<int>&right_diagonal){
        if(top[row]==1) return false;
        if(left_diagonal[row+col]==1) return false;
        if(right_diagonal[n-1+col-row]==1) return false;
        return true;
    }
    
    void recur(int col, vector<int>&matrix, vector<vector<int>>&ans ,int n, vector<int>&top, vector<int>&left_diagonal, vector<int>&right_diagonal){
        if(col==n) {
            ans.push_back(matrix);
            return;
        }
        for(int row=0; row<n; row++){
            if(isValid(row, col, n, top, left_diagonal, right_diagonal)){
                matrix.push_back(row+1);
                top[row]=1;
                left_diagonal[row+col]=1;
                right_diagonal[n-1+col-row]=1;
                
                recur(col+1, matrix,ans, n, top, left_diagonal, right_diagonal);
                
                matrix.pop_back();
                top[row]=0;
                left_diagonal[row+col]=0;
                right_diagonal[n-1+col-row]=0;
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        // code here
        // vector<vector<char>>matrix( n , vector<char> (n));
        vector<int> matrix;
        vector<vector<int>>ans;
        vector<int>top (n,0);
        vector<int>left_diagonal((2*n)-1,0);
        vector<int>right_diagonal((2*n)-1,0);
        recur(0,matrix, ans, n, top, left_diagonal, right_diagonal);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends