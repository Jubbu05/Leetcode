#include <bits/stdc++.h>

// Recursive function to find word break combinations
void solve(int idx, string &s, map<string, bool> &mp, string cur, vector<string> &res)
{
    // If we have reached the end of the string, add the current combination to the result
    if (idx == s.size())
    {
        res.push_back(cur);
        return;
    }

    // Iterate over the string from the current index
    for (int i = idx; i < s.size(); i++)
    {
        string tmp = s.substr(idx, i - idx + 1); // Get the substring from idx to i

        // If the substring is present in the dictionary, recursively call solve function
        // with the next index and update the current combination
        if (mp[tmp])
        {
            solve(i + 1, s, mp, cur + tmp + " ", res);
        }
    }
}

// Function to perform word break and return the combinations
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    map<string, bool> mp;

    // Populate the map with dictionary words
    for (auto &x : dictionary)
    {
        mp[x] = true;
    }

    vector<string> res;
    solve(0, s, mp, "", res); // Call the solve function to find word break combinations
    return res;
}
