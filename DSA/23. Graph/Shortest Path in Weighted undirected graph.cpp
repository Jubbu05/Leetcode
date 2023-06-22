class Solution
{
public:
    // source vertex is 1 and destination vertex is n
    vector<int> shortestPath(int n, int m, vector<vector<int>> &edges)
    {
        //{distance,node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        // 1 base indexing as per question
        vector<int> dist(n + 1, 1e9);
        vector<int> parent(n + 1, 1e9);
        vector<pair<int, int>> adj[n + 1];

        for (auto it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }

        // source node is 1
        dist[1] = 0;
        //{distance,node}
        minHeap.push({0, 1});

        while (!minHeap.empty())
        {
            int distance = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();

            for (auto it : adj[node])
            {
                int nextNode = it.first;
                int nextDistance = it.second;

                if (distance + nextDistance < dist[nextNode])
                {
                    parent[nextNode] = node;
                    dist[nextNode] = distance + nextDistance;
                    minHeap.push({dist[nextNode], nextNode});
                }
            }
        }

        // can't reach destination
        if (dist[n] == 1e9)
        {
            return {-1};
        }

        vector<int> path;
        int node = n;
        // not a source node
        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        // adding source node
        path.push_back(1);

        reverse(path.begin(), path.end());

        return path;
    }
};