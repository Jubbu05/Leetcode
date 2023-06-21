// anyone who is a part of cycle cannot be a safe node
// anyone who leads to a cycle cannot be a safe node
class Solution
{
private:
    // Function to detect cycle in a directed graph.
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[], int check[])
    {
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for (auto it : adj[node])
        {
            // when the node is not visited
            if (!vis[it])
            {
                // we found a cycle so cant be a safe node
                if (dfsCheck(it, adj, vis, pathVis, check) == true)
                {
                    check[node] = 0;
                    return true;
                }
            }
            // if the node has been previously visited
            // but it has to be visited on the same path
            else if (vis[it] == 1 && pathVis[it] == 1)
            {
                check[node] = 0;
                return true;
            }
        }
        // dfs is complete no cycle found
        // this mean that the node is
        check[node] = 1;

        // remove the node from the current path
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[])
    {
        int vis[V] = {0};
        int pathVis[V] = {0};
        int check[V] = {0};
        vector<int> safeNodes;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsCheck(i, adj, vis, pathVis, check);
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1)
                safeNodes.push_back(i);
        }
        return safeNodes;
    }
};