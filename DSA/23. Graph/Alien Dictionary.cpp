class Solution
{
private:
    // works for multiple components as well
    vector<int> topoSort(int V, vector<int> adj[])
    {
        vector<int> topo;
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

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node])
            {
                indegree[it]--;

                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        return topo;
    }

public:
    string findOrder(string dict[], int N, int K)
    {

        // creating a graph
        vector<int> adj[K];

        for (int i = 0; i < N - 1; i++)
        {
            string s1 = dict[i];
            string s2 = dict[i + 1];

            // comparing every chatacter of both strings
            int len = min(s1.size(), s2.size());
            for (int ptr = 0; ptr < len; ptr++)
            {
                if (s1[ptr] != s2[ptr])
                {
                    // edge from s1[ptr] to s2[ptr]
                    // coz s1 appears before s2 in the dictionary
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        // now fing the topological sort of the graph
        vector<int> topo = topoSort(K, adj);

        string ans = "";

        for (auto it : topo)
        {
            ans = ans + char(it + 'a');
        }

        return ans;
    }
};