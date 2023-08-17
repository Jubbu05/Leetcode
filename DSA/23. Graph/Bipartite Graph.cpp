#include <bits/stdc++.h>
bool isGraphBirpatite(vector<vector<int>> &edges)
{
    // Write your code here.
    int n = edges.size();
    vector<int> adj[n];
    for (int i = 0; i < edges.size(); i++)
    {
        for (int j = 0; j < edges[i].size(); j++)
        {
            if (edges[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    queue<int> q;
    vector<int> color(n, 0);
    q.push(0);
    color[0] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (color[it] == 0)
            {
                color[it] = -color[node];
                q.push(it);
            }
            else if (color[node] == color[it])
            {
                return false;
            }
        }
    }
    return true;
}