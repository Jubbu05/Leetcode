class Solution
{
private:
    bool detect(int src, vector<int> adj[], int vis[])
    {
        queue<pair<int, int>> q;

        vis[src] = 1;
        q.push({src, -1});

        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push({it, node});
                }
                // if someone is visited and it is not parent of current node then there is a cycle
                else if (it != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<int> adj[])
    {
        int vis[V] = {0};

        //for disconnected graph
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect(i, adj, vis) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};