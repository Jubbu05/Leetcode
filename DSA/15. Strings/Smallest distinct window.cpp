class Solution
{
    // https://www.youtube.com/watch?v=zm50uGBsSz4
public:
    int findSubString(string str)
    {
        set<char> s;
        for (auto c : str)
        {
            s.insert(c);
        }

        unordered_map<char, int> mp;
        int i = 0, j = 0;
        int ans = str.length(); // max at if all the char are different
        int n = s.size();
        while (i < str.length())
        {
            mp[str[i]]++;
            if (mp.size() == s.size())
            {
                while (mp[str[j]] > 1)
                {
                    mp[str[j]]--;
                    j++;
                }
                ans = min(ans, i - j + 1);
            }
            else
            {
                i++;
            }
        }
        return ans;
    }
};
