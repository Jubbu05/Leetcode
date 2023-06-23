// WORKS FOR NEGATIVE WEIGHTS ALSO
// WORKS FOR DIRTCTED
// IF GIVEN GRAPH IS UNDIRECTED THEN MAKE IT DIRECTED BY ADDING REVERSE EDGE OF EVERY EDGE WITH SAME EDGE WEIGHT
// ALGO STATES RELEX ALL EDGES N-1 TIMES SEQUNTIALLY MEANS
// if(dist[u] + wt < dist[v])  dist[v] = dist[u] + wt; THIS WILL BE DONE N-1 TIMES

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {

        vector<int> dist(V, 1e8);

        dist[S] = 0;

        // relexation of edges n-1 times
        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int wt = it[2];

                // if its reachable
                if (dist[u] != 1e8 && dist[u] + wt < dist[v])
                {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        //Nth relexation to check for negative cycle
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (dist[u] != 1e8 && dist[u] + wt < dist[v])
            {
                return {-1};
            }
        }

        return dist;
    }
};