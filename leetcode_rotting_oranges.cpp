class Solution {
public:
    
    int orangesRotting(vector<vector<int>>& grid) {
        int R=grid.size();
        int C=grid[0].size();
        int count=0;
        queue<pair<pair<int,int>,int>>que;
        //bfs start
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(grid[i][j]==2){
                    que.push({{i,j},0});
                }
            }
        }
        pair<pair<int,int>,int>front;
        int i, j, level;
        while(!que.empty()){
            front=que.front();
            que.pop();
            i=front.first.first;
            j=front.first.second;    
            level=front.second;
            grid[i][j]=2;       
            count=max(count,level) ;
            if(i+1<R && grid[i+1][j]==1){
                grid[i+1][j]=-1;
                que.push({{i+1,j},level+1});
            }
            if(i-1>=0&&grid[i-1][j]==1){
                grid[i-1][j]=-1;
                que.push({{i-1,j},level+1});
            }
            if(j+1<C&&grid[i][j+1]==1){
                grid[i][j+1]=-1;
                que.push({{i,j+1},level+1});
            }
            if(j-1>=0&&grid[i][j-1]==1){
                grid[i][j-1]=-1;
                que.push({{i,j-1},level+1});
            }
        }
        //bfs end
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return count;
    }
};