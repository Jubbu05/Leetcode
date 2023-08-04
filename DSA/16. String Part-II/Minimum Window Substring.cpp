class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.length() == 0 || t.length() == 0 || s.length() < t.length())
            return "";

        vector<int> v(256, 0);

        for (int i = 0; i < t.length(); i++)
        {
            v[t[i]]++;
        }

        int start = 0, end = 0, ans_start = 0;
        int minlen = INT_MAX;
        int count = 0;

        // expand window
        while (end < s.length())
        {

            // present in t
            if (v[s[end]] > 0)
            {
                count++; // including that char at window
            }
            // decrease freq coz we traversed it
            v[s[end]]--;

            // window is valid
            //move start to remove unwanted chars coz we have to find min window
            while (count == t.length())
            {
                if(minlen > end-start+1){
                    minlen = end-start+1;
                    ans_start = start;
                }
                v[s[start]]++;
                if(v[s[start]] > 0){
                    count--;
                }
                start++;
            }
            // expand window
            end++;
        }
        if(minlen == INT_MAX) return "";

        return s.substr(ans_start, minlen);
    }
};