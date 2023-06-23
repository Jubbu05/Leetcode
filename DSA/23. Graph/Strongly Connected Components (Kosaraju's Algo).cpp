// /Kosaraju's Algorithm.
// SORT ALL THE EDGES ACCORDING TO THEIR FINISHING TIME
// REVERSE THE GRAPH
// DO A DFS
class Solution
{
private:
    void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
    {
        vis[node] = 1;
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, vis, adj, st);
            }
        }

        st.push(node);
    }

private:
    void dfs3(int node, vector<int> &vis, vector<int> adjT[])
    {
        vis[node] = 1;
        for (auto it : adjT[node])
        {
            if (!vis[it])
            {
                dfs3(it, vis, adjT);
            }
        }
    }

public:
    // Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        // THIS WILL STORE THE NODES IN THE ORDER OF THEIR FINISHING TIME
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, vis, adj, st);
            }
        }

        // REVRESE THE GRAPH
        vector<int> adjT[V];
        for (int i = 0; i < V; i++)
        {
            vis[i] = 0; // MAKE ALL NODES UNVISITED COZ NEED TO DO DFS AGAIN
            for (auto it : adj[i])
            {
                // i -> it
                // it -> i -> WE WANT THIS
                adjT[it].push_back(i);
            }
        }

        // PERFORM DFS ACCORDING TO THE FINISHING TIME WHICH IS STORED IN STACK
        int scc = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (!vis[node])
            {
                dfs3(node, vis, adjT);
                scc++;
            }
        }
        return scc;
    }
};