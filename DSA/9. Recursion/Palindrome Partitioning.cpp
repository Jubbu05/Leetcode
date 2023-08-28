#include <bits/stdc++.h>
bool isPalindrome(string str, int s, int e){
    while(s <= e){
        if(str[s++] != str[e--]){
            return false;
        }
    }
    return true;
}
void solve(int ind, string s, vector<string>& temp, vector<vector<string>>& ans){
    if(ind == s.length()){
        ans.push_back(temp);
    }
    
    for(int i = ind; i <= s.length(); i++){
        if(isPalindrome(s, ind, i)){
            temp.push_back(s.substr(ind, i-ind+1));
            solve(i+1, s, temp, ans);
            temp.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> temp;
    solve(0, s, temp, ans);
    return ans;
}
