#include <bits/stdc++.h> 
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans;
    stack<int> s;.

    for(int i=n-1; i>=0; i--){
        int ele = arr[i];
        while(!s.empty() && s.top() >= ele){
            s.pop();
        }
        int res = (s.empty()) ? -1 : s.top();
        ans.push_back(res);
        s.push(arr[i]);
    }
    return res;
}