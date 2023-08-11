// O(n+m) space
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;
        for(int i=0;i<s.length();i++){
            if(st1.empty() && s[i]=='#' ){
                continue;
            }
            if(s[i]=='#' && !st1.empty()){
                st1.pop();
            }else{
                st1.push(s[i]);
            }
        }
         for(int i=0;i<t.length();i++){
            if(st2.empty() && t[i]=='#' ){
                continue;
            }
            if(t[i]=='#' && !st2.empty()){
                st2.pop();
            }else{
                st2.push(t[i]);
            }
        }
        return st1==st2;
    }
};

//------------------------------------------------------------
//O(1) space
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string sc,tc;
        for(int i=0;i<s.size();i++){
            if(s[i]>='a' && s[i]<='z'){
                sc.push_back(s[i]);
            }
            else{
                if(sc.empty()) continue;
                sc.pop_back();
            }
        }
        for(int i=0;i<t.size();i++){
            if(t[i]>='a' && t[i]<='z'){
                 tc.push_back(t[i]);
            }
            else{
                if(tc.empty()) continue;
                 tc.pop_back();
            }
        }
        if(sc == tc) return 1;
        else return 0;
    }
};