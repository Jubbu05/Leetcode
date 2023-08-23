class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        int mod = 1e9 + 7;
        vector<pair<int, int>> adj[n];

        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> dist(n, 1e15), ways(n, 0);

        pq.push({0, 0});
        dist[0] = 1;
        ways[0] = 1;

        while (!pq.empty())
        {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int wt = it.second;
                
                //if the distance of the adjacent node is greater than the distance of the current node + weight of the edge
                //then update the distance of the adjacent node and push it in the priority queue
                if (dis + wt < dist[adjNode])
                {
                    dist[adjNode] = dis + wt;
                    ways[adjNode] = ways[node]; //update the ways of the adjacent node
                    pq.push({dis + wt, adjNode});
                }
                //if the distance of the adjacent node is equal to the distance of the current node 
                //it means that there are multiple ways to reach the adjacent node
                //so we add the ways of the current node to the ways of the adjacent node as both are equal
                else if (dis + wt == dist[adjNode])
                {
                    ways[adjNode] = (ways[node] + ways[adjNode]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};