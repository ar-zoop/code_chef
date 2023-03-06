//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
        // code here
        int N=details.size();
        int parent[N];
        for(int i=0; i<N; i++){
            parent[i]=i;
        }
        map<string,int> dict;
        for(int i=0; i<N; i++){
            for(int j=0; j<details[i].size(); j++){
                if(j==0) continue;
                else{
                    if(dict.find(details[i][j])==dict.end()){
                        dict[details[i][j]]=i;
                    }
                    else{
                        parent[i]=dict[details[i][j]];
                    }
                }
            }
        }
        map<string, int>:: iterator itr= dict.begin();
        
        while(itr!=dict.end()){
            cout<<itr->first<<" "<<itr->second<<endl;
        }
    return details;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<string>> adj;

        for (int i = 0; i < n; i++) {
            vector<string> temp;
            string s;
            cin >> s;
            temp.push_back(s);
            int x;
            cin >> x;

            for (int j = 0; j < x; j++) {
                string s1;
                cin >> s1;
                temp.push_back(s1);
            }
            adj.push_back(temp);
        }

        Solution obj;
        vector<vector<string>> res = obj.mergeDetails(adj);
        sort(res.begin(),res.end(),[](const vector<string>& a, const vector<string>& b){
            return a[0]<=b[0];
        });
        cout << "[";
        for (int i = 0; i < res.size(); ++i) {
            cout << "[";
            for (int j = 0; j < res[i].size(); j++) {
                if (j != res[i].size() - 1)
                    cout << res[i][j] << ","
                         << " ";
                else
                    cout << res[i][j];
            }
            if (i != res.size() - 1)
                cout << "], ";
            else
                cout << "]";
        }
        cout << "]"
             << "\n";
    }
}

// } Driver Code Ends