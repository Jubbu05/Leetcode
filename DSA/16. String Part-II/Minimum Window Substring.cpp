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
            // move start to remove unwanted chars coz we have to find min window
            while (count == t.length())
            {
                if (minlen > end - start + 1)
                {
                    minlen = end - start + 1;
                    ans_start = start;
                }
                v[s[start]]++;
                if (v[s[start]] > 0)
                {
                    count--;
                }
                start++;
            }
            // expand window
            end++;
        }
        if (minlen == INT_MAX)
            return "";

        return s.substr(ans_start, minlen);
    }
};

class Solution {
public:
    string minWindow(string s, string t) {
        if(t == "") return "";
        unordered_map<char,int> mp_t;
        unordered_map<char,int> mp_s;
        int m=s.length();
        int n=t.length();
        if(n>m){
            return "";
        }
        pair<int,int> ans={-1,INT_MAX};
        //storing freq of t in a map
        for(auto it:t){
            mp_t[it]++;
            it++;
        }
        int st=0;
        int e=0;
        int need=mp_t.size();
        int have=0;
        while(e<m){
            mp_s[s[e]]++;
            if(mp_t[s[e]]>0 && mp_t[s[e]]==mp_s[s[e]]){
                have++;
            }
            while(have==need){
                if(e-st+1<ans.second){
                    ans={st,e-st+1};
                }
                if(mp_t[s[st]]>0 && mp_s[s[st]]-1<mp_t[s[st]]){
                    have--;
                }
                mp_s[s[st]]--;
                st++;
            }
            e++;
            }
        string finalans="";
        if(ans.first>=0){ 
        finalans=s.substr(ans.first,ans.second);
        }
        return finalans;
    }
};