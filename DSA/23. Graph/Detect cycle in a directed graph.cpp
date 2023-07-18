// //DFS
class Solution
{
public:
    // Function to detect cycle in a directed graph.
    bool dfs(int node, vector<int> adj[], int vis[], int pathvis[])
    {
        vis[node] = 1;
        pathvis[node] = 1;

        for (auto it : adj[node])
        {
            // when node is not visited
            if (!vis[it])
            {
                if (dfs(it, adj, vis, pathvis) == true)
                {
                    return true;
                }
            }
            // if the node has been previously visited
            // but it has to be visited on the same path
            else if (vis[it] == 1 && pathvis[it] == 1)
            {
                return true;
            }
        }
        //unmarking the node when going back
        pathvis[node] = 0;

        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        int vis[V] = {0};
        int pathvis[V] = {0};

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs(i, adj, vis, pathvis) == true)
                {
                    return true;
                }
            }
        }
        return false;
    }
};

// BFS
class Solution
{
public:
    bool isCyclic(int V, vector<int> adj[])
    {
        queue<int> q;
        int indegree[V] = {0};

        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        // Push all the nodes with indegree 0
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // vector<int> topo;
        int cnt = 0;

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            // topo.push_back(node);
            cnt++;

            for (auto it : adj[node])
            {
                indegree[it]--;

                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        //contains all the elements in the topo sort so no cycle
        if (cnt == V)
            return false;
        return true;
    }
};
