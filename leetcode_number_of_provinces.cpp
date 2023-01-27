class Solution
{
public:
    void Dfs(int node, int N, vector<vector<int>> &matrix, vector<bool> &vis)
    {
        vis[node] = 1;
        for (int i = 0; i < N; i++)
        {
            if (matrix[node][i] == 1 && node != i && !vis[i])
            {
                Dfs(i, N, matrix, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int N = isConnected.size();
        int count = 0;
        int i, j;
        vector<bool> vis(N, 0);
        for (int i = 0; i < N; i++)
        {
            if (!vis[i])
            {
                count++;
                Dfs(i, N, isConnected, vis);
            }
        }

        return count;
    }
};