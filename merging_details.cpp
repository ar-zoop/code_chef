//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class disjointSet{
    public:
    vector <int> parent, size;
    disjointSet(int V){
        parent.resize(V+1);
        // rank.resize(V+1, 0);
        for(int i=0; i<V+1; i++){
            parent[i]=i;
        }
        size.resize(V+1, 1);
    }
    int getParent(int u){
        if(parent[u]==u) return u;
        return parent[u] = getParent(parent[u]);
    }

    void unionBySize(int u, int v){
        int upu, upv;
        upu = getParent(u);
        upv = getParent(v);
        if (upu == upv)
        {
            // cout << "Cycle detected";
            return;
        }
        if (size[upu] > size[upv])
        {
            parent[upv] = upu;
            size[upu]+=size[upv];
        }
        else if (size[upv] > size[upu])
        {
            parent[upu] = upv;
            size[upv]+=size[upu];
        }
        else
        {
            parent[upu] = upv;
            size[upv]+=size[upv];
        }
    }
};

class Solution {
  public:
    vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
        // code here
        int N=details.size();
        disjointSet ds(N);
        map<string,int> dict;
        for(int i=0; i<N; i++){
            for(int j=1; j<details[i].size(); j++){
               
                if(dict.find(details[i][j])==dict.end()){
                    dict[details[i][j]]=i;
                }
                else{
                    ds.unionBySize(i, dict[details[i][j]]);
                }
                
            }
        }
      
        
      vector<string>intmdt[N];
      map<string,int>::iterator itr=dict.begin();
      string key;
      int value;
      int up;
      
      while(itr!=dict.end()){
          key=itr->first;
          value=itr->second;
          up=ds.getParent(value);
          intmdt[up].push_back(key);
          itr++;
      }
      
      vector<vector<string>>res;
      for(int i=0; i<N; i++){
          if(intmdt[i].size()==0){
              continue;
          }
          else{
              sort(intmdt[i].begin(), intmdt[i].end());
              vector<string> temp;
              temp.push_back(details[i][0]);
              for(auto it: intmdt[i]){
                  temp.push_back(it);
              }
              res.push_back(temp);
          }
      }
      sort(res.begin(), res.end(), greater<vector<string>>());
      return res;
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