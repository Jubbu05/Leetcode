#include <bits/stdc++.h> 
vector<int> computeLPS(string p, int n)
{
    int i = 1, len = 0;
    vector<int> lps(n, 0);
    while (i < n)
    {
        if (p[i] == p[len])
        {
            lps[i] = len + 1;
			len++;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

bool KMP(string s, string p){
    int n = s.length();
    int m = p.length();
    vector<int> lps = computeLPS(p, m);

    int i = 0;
    int j = 0;

    while(i < n){
        if(s[i] == p[j]){
            i++;
            j++;
        }
        else{
            if(j != 0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }

        if(j==m){
            return true;
        }
    }
    return false;
}
bool findPattern(string p, string s)
{
    return KMP(s, p);
}