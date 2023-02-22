//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> dist_node_tracker;
        vector<int>shortestDist(V,1e9);
        int node, dist;
        shortestDist[S]={0};
        dist_node_tracker.insert({0,S});
        while(!dist_node_tracker.empty()){
            auto it=*(dist_node_tracker.begin());
            dist=it.first;
            node=it.second;
            dist_node_tracker.erase(dist_node_tracker.begin());
            int neighbourDist, neighbour;
            //find neighbours
            for(auto vec:adj[node]){
                neighbour=vec[0];
                neighbourDist=vec[1];
                if(shortestDist[neighbour]>neighbourDist+dist){
                    if(shortestDist[neighbour]!=1e9){
                        dist_node_tracker.erase({shortestDist[neighbour],neighbour});
                    }
                    shortestDist[neighbour]=neighbourDist+dist;
                    dist_node_tracker.insert({neighbourDist+dist,neighbour});
                }
            }
        }
        return shortestDist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends