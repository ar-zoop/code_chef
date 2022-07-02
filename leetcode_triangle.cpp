class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        long long int memo[200][200]={0};
        for (int j=0;j<n;j++){
            memo[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int pick=triangle[i][j]+ memo[i+1][j];
                int not_pick=triangle[i][j]+memo[i+1][j+1];
                memo[i][j]=min(pick,not_pick);
            }
        }
        return memo[0][0];
    }
};