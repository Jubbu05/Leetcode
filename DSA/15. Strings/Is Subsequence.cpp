class Solution {
public:
    bool helper(string s, string t, int n, int m){
        if(n == 0) return true;
        if(m == 0) return false;
        
        // If last characters of two strings are matching
        if(s[n-1] == t[m-1]){
            return helper(s, t, n-1, m-1);
        }
        // If last characters are not matching
        return helper(s, t, n, m-1);
    }
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        return helper(s,t,n,m);
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();
        int i = 0, j = 0;
        while(i < n && j < m){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return (i == n) ? true : false;
    }
};