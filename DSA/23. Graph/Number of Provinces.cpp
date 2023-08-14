class Solution
{
public:
    // void dfs(int node, vector<int> adj[], vector<int> &vis)
    // {
    //     vis[node] = 1;
    //     for (auto it : adj[node])
    //     {
    //         if (!vis[it])
    //             dfs(it, adj, vis);
    //     }
    // }
    void bfs(int node, vector<int> adj[], vector<int> &vis)
    {
        vis[node] = 1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            for(auto it : adj[ele]){
                if(!vis[it]){
                    bfs(it, adj, vis);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj)
    {
        int V = adj.size();
        // converting ajacency matrix to adjacency list
        vector<int> adjList[V];
        for (int i = 0; i < adj.size(); i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                if (adj[i][j] == 1 && i != j)
                {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                bfs(i, adjList, vis);
                cnt++;
            }
        }
        return cnt;
    }
};

//------------------------------------------------------------------------------------------


class DisjointSet
{

public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    int numProvinces(vector<vector<int>> adj, int V)
    {
        DisjointSet ds(V);

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (adj[i][j] == 1)
                {
                    ds.unionBySize(i, j);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < V; i++)
        {
            if (ds.parent[i] == i)
                cnt++;
        }

        return cnt;
    }
};