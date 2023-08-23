#include <bits/stdc++.h> 
void solve(vector<int>v,int i,vector<vector<int>>& ans,vector<int> temp){
    if(i==v.size()){
        ans.push_back(temp);
        return;
    }

    //pick
    temp.push_back(v[i]);
    solve(v,i+1,ans,temp);
    temp.pop_back();

    //notpick
    solve(v,i+1,ans,temp);
}
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>> ans;
    vector<int> temp;
    solve(v,0,ans,temp);
    return ans;
}