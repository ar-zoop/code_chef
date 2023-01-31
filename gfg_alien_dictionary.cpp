//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string topoSortKahns(set<int> adj[], bool vis[], int K){
        string order="";
        int indegree[K]={0};
        queue<int>que;
        int size;
        for(int i=0; i<K; i++){
            for (auto itr : adj[i]){
                indegree[itr]++;
            }
        }
        for(int i=0; i<K; i++){
            if(indegree[i]==0){
                que.push(i);
                order+=char(i+'a');
            }
        }
        int front;
        while(!que.empty()){
            front=que.front();
            que.pop();
            vis[front]=1;
            for (auto itr : adj[front]){
                indegree[itr]--;
                if(indegree[itr]==0){
                    que.push(itr);
                    order+= char(itr+'a');
                }
            }
            // for(int i=0; i<adj[front].size(); i++){
            //     indegree[adj[front][i]]--;
            //     if(indegree[adj[front][i]]==0){
            //         que.push(indegree[adj[front][i]]);
            //         order+= char(indegree[adj[front][i]]+'a');
            //     }
            // }
        }
        // cout<<order<<endl;
        return order;
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        set<int> adj [K];
        for(int i=0; i<N; i++){
            int j=i+1;
            int size=min(dict[i].length(), dict[j].length());
            for(int k=0; k<size; k++){
                if(dict[i][k]!=dict[j][k]){
                    adj[dict[i][k]-'a'].insert(dict[j][k]-'a');
                    break;
                }
            }
        }
        bool vis[K]={0};
        string order;
        order= topoSortKahns(adj,vis,K);
        // cout<<order<<endl;
        for(int i=0; i<K;i++){
            if(!vis[i]){
                order+=(i+'a');
            }
        }
        // cout<<order<<endl;
        return order;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends