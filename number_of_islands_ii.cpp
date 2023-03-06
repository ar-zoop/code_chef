class disjointSet
{
public:
    vector<int> parent, rank, size;
    disjointSet(int V)
    {
        parent.resize(V + 1);
        rank.resize(V + 1, 0);
        for (int i = 0; i < V + 1; i++)
        {
            parent[i] = i;
        }
        size.resize(V + 1, 1);
    }
    int getParent(int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = getParent(parent[u]);
    }

    void unionByRank(int u, int v)
    {
        int upu, upv;
        upu = getParent(u);
        upv = getParent(v);
        if (upu == upv)
        {
            // cout<<"Cycle detected";
            return;
        }
        if (rank[upu] > rank[upv])
        {
            parent[upv] = upu;
        }
        else if (rank[upv] > rank[upu])
        {
            parent[upu] = upv;
        }
        else
        {
            parent[upu] = upv;
            rank[upv]++;
        }
    }

    void unionBySize(int u, int v)
    {
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

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q)
{
    // Write your code here.
    disjointSet ds(n * m);
    vector<int> islandCount;
    int islands = 0;
    int r, c, newR, newC;
    int delR[] = {-1, 0, +1, 0};
    int delC[] = {0, +1, 0, -1};
    vector<vector<int>> grid(n, vector<int>(m, 0));
    for (auto vec : q)
    {
        r = vec[0];
        c = vec[1];
        if (grid[r][c])
        {
            islandCount.push_back(islands);
            continue;
        }
        int gridNo = (r * m) + c;
        int up = ds.getParent(gridNo);
        grid[r][c] = 1;
        islands++;
        for (int i = 0; i < 4; i++)
        {
            newR = r + delR[i];
            newC = c + delC[i];
            if (newR < 0 || newR >= n || newC < 0 || newC >= m || !grid[newR][newC])
                continue;
            int adjGridNo = (newR * m) + newC;
            int upAdj = ds.getParent(adjGridNo);
            if (upAdj != up)
            {
                ds.unionBySize(gridNo, adjGridNo);
                islands--;
            }
        }
        // if(ds.getParent(gridNo)==gridNo) islands++;
        islandCount.push_back(islands);
    }
    return islandCount;
}