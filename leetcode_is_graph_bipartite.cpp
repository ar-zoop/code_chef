class Solution {
public:
    bool bfs(int i, vector<int>&color, int N, vector<vector<int>>& adj){
        queue<pair<int, bool>>que;
        que.push({i,0});
        pair<int,bool> front;
        int node;
        bool col;
        while(!que.empty()){
            front=que.front();
            node=front.first;
            col=front.second;
            que.pop();
            color[node]=col;
            for(int i=0; i<adj[node].size(); i++){
                if(color[adj[node][i]]==-1){
                    que.push({adj[node][i], !col});
                }
                else if(color[adj[node][i]]==col) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int N=adj.size();
        vector<int>color(N,-1);
        for(int i=0; i<N; i++){
            if(color[i]==-1){
                if(!bfs(i,color,N, adj)){
                    return false;
                };
            }
        }
        return true;
    }
};