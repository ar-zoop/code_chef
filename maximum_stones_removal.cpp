//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class disjointSet
{
public:
    vector<int> parent, size;
    disjointSet(int V)
    {
        parent.resize(V + 1);
        // rank.resize(V+1, 0);
        for (int i = 0; i < V + 1; i++)
        {
            parent[i] = -1;
        }
        size.resize(V + 1, 1);
    }
    int getParent(int u)
    {
        if (parent[u] == -1)
            return -1;
        if (parent[u] == u)
            return u;
        return parent[u] = getParent(parent[u]);
    }

    void unionBySize(int u, int v)
    {
        int upu, upv;
        upu = getParent(u);
        upv = getParent(v);
        
        if (upu == -1 || upv == -1)
        {
            // cout << "Cycle detected";
            if (upv == -1)
            {
                parent[u] = u;
                parent[v] = u;
                size[u] += size[v];
            }
            else
            {
                parent[v] = v;
                parent[u] = v;
                size[v] += size[u];
            }
            return;
        }
        if (upu == upv)
            return;
        if (size[upu] > size[upv])
        {
            parent[upv] = upu;
            size[upu] += size[upv];
        }
        else if (size[upv] > size[upu])
        {
            parent[upu] = upv;
            size[upv] += size[upu];
        }
        else
        {
            parent[upu] = upv;
            size[upv] += size[upv];
        }
    }
};

class Solution
{
public:
    int maxRemove(vector<vector<int>> &stones, int n)
    {

        int totalCols = INT_MIN, totalRows = INT_MIN;
        int x, y, gridNo;

        for (int i = 0; i < stones.size(); i++)
        {
            x = stones[i][0];
            y = stones[i][1];
            totalRows = max(totalRows, x);
            totalCols = max(totalCols, y);
        }

        disjointSet ds((totalRows + 1) * (totalCols + 1));
        int leftmost, topmost;

        for (int i = 0; i < stones.size(); i++)
        {
            x = stones[i][0];
            y = stones[i][1];
            // cout<<"x&Y->"<<x<<" "<<y<<endl;
            gridNo = x * (totalCols + 1) + y;
            // cout<<"gridNo"<<gridNo<<endl;
            leftmost = x * (totalCols + 1);
            topmost = y;
            // cout<<"leftmost="<<leftmost <<" topmost="<<topmost<<endl;
            
                // ds.unionBySize(leftmost, gridNo);
                // cout<<"connected with leftmost"<<endl<<endl;           

           
                    // ds.unionBySize(topmost, gridxNo);
                // cout<<"connected with topmost"<<endl<<endl;
            
        }

        // return segment

        int removedStones = 0;
        // for (int i = 0; i < ds.size.size(); i++)
        // {
            // cout<<ds.size[i]<<" ";
            // if(ds.size[i]<0) continue;
            // cout<<ds.size[i]<<" ";
            // removedStones += ds.size[i] - 1;
        // }
        for(int i=0; i<ds.parent.size(); i++){
                cout << i <<ds.parent[i] <<" "<<ds.size[i] << endl;
                if (ds.parent[i] == i)
                removedStones += ds.size[i];
        }
        return removedStones;

        // return 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i)
        {
            vector<int> temp;
            for (int i = 0; i < 2; ++i)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends