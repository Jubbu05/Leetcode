#include <bits/stdc++.h>
void solve(int ind, int n, string temp, vector<string>& ans){
    if(ind == n){
        ans.push_back(temp);
        return;
    }
    
    temp.push_back('0');
    solve(ind+1, n, temp, ans);
    temp.pop_back();

    if(temp.back() == '0' || temp.empty()){
        temp.push_back('1');
        solve(ind+1, n, temp, ans);
        temp.pop_back();
    }
}
vector<string> generateString(int n) {
    vector<string> ans;
    string temp = "";

    solve(0, n, temp, ans);
    return ans;
}