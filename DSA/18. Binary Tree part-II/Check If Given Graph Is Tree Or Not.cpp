// Conditions -> No cycle + connected

bool isCyclic(int src, int parent, vector<vector<int>>& vec, vector<bool>& vis)
{
    vis[src] = true;
    for (auto it : vec[src])
    {
        if (!vis[it])
        {
            if (isCyclic(it, src, vec, vis))
            {
                return true;
            }
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}

bool isTree(int n, vector<vector<int>> vec)
{
    vector<bool> vis(n, false);

    int startingNode = 0;
    if (isCyclic(startingNode, -1, vec, vis))
    {
        return false;
    }

    for (int u = 0; u < n; u++)
    {
        if (!vis[u])
        {
            return false;
        }
    }
    return true;
}