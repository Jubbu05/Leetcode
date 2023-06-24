// // Priority Queue
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        //{distance,node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> dist(V, 1e9);

        dist[S] = 0;
        minHeap.push({0, S});

        while (!minHeap.empty())
        {
            int distance = minHeap.top().first;
            int node = minHeap.top().second;
            minHeap.pop();

            for (auto it : adj[node])
            {
                int nextNode = it[0];
                int nextDistance = it[1];

                if (distance + nextDistance < dist[nextNode])
                {
                    dist[nextNode] = distance + nextDistance;
                    minHeap.push({dist[nextNode], nextNode});
                }
            }
            return dist;
        }
    }
};

// // SET - Unique and Smallest at the top
// class Solution
// {
// public:
//     // Function to find the shortest distance of all the vertices
//     // from the source vertex S.
//     vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
//     {
//         set<pair<int, int>> st;
//         vector<int> dist(V, 1e9);

//         dist[S] = 0;
//         //{distance,node}
//         st.insert({0, S});

//         while (!st.empty())
//         {
//             // this will give us the value
//             auto it = *(st.begin());
//             int distance = it.first;
//             int node = it.second;
//             st.erase(it);

//             for (auto it : adj[node])
//             {
//                 int nextNode = it[0];
//                 int nextDistance = it[1];

//                 if (distance + nextDistance < dist[nextNode])
//                 {
//                     //erase if existed
//                     if(dist[nextNode]!=1e9){
//                         st.erase({dist[nextNode],nextNode});
//                     }

//                     dist[nextNode] = distance + nextDistance;
//                     st.insert({dist[nextNode], nextNode});
//                 }
//             }
//         }
//         return dist;
//     }
// };