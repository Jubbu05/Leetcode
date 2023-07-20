#include <bits/stdc++.h>
vector<string> subsequences(string s)
{
    int n = s.length();
    vector<string> ans;

    // 0 -> 2^n - 1
    for (int num = 0; num < (1 << n); num++)
    {
        string sub = "";
        for (int i = 0; i < n; i++)
        {
            // check if the ith bit is set or not
            if (num & (1 << i))
            {
                sub += s[i];
            }
        }
        if (sub.length() > 0)
        {
            ans.push_back(sub);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

//---------------------------------------------------------

#include <bits/stdc++.h>
void solve(int index, string &str, vector<string> &ans, string s)
{
    if (index == str.size())
    {
        if (s.size() > 0)
            ans.push_back(s);
        return;
    }
    // Take
    s.push_back(str[index]);
    solve(index + 1, str, ans, s);
    // Not Take
    s.pop_back();
    solve(index + 1, str, ans, s);
}
vector<string> subsequences(string str)
{
    vector<string> ans;
    string s = "";
    solve(0, str, ans, s);
    return ans;
}