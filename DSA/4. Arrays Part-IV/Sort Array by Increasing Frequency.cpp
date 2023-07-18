string s;
bool my_compare(char c1, char c2)
{
    return s.find(c1) < s.find(c2);
}
class Solution
{
public:
    string customSortString(string order, string str)
    {
        s = order;
        sort(str.begin(), str.end(), my_compare);
        return str;
    }
};

class Solution
{
public:
    string customSortString(string order, string str)
    {
        map<char, int> mp;
        string ans = "";

        for (auto x : str)
        {
            mp[x]++;
        }

        for (auto x : order)
        {
            if (mp.find(x) != mp.end())
            {
                auto temp = mp.find(x);
                int cnt = temp->second;

                string s(cnt, x); // this will create a string of cnt length with all characters as x
                ans += s;
                mp.erase(x);
            }
        }

        for (auto x : mp)
        {
            string s(x.second, x.first);
            ans += s;
        }

        return ans;
    }
};