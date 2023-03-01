//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int SIZE=arr.size();
        queue<pair<int,int>>q;
        q.push({0,start});
        vector<int> vis(1e5, 1e9);
        vis[start]=0;
        int node,level;
        double newNode;
        while(!q.empty()){
            node=q.front().second;
            level=q.front().first;
            q.pop();
            for(int i=0; i<SIZE; i++){
                newNode=node*arr[i] % 100000;
                if(vis[newNode]>level+1){
                    vis[newNode]=level+1;
                    q.push({level+1, newNode});
                }
            }
        }
        if(vis[end]==1e9)return -1;
        return vis[end];
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends