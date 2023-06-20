#include <bits/stdc++.h> 
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    priority_queue<pair<int, pair<int, int>>> pq;

    //pushing the last elements of both soetd arrays
    pq.push({a[n-1] + b[n-1], {n-1, n-1}});

    set<pair<int, int>> s;
    s.insert({n-1, n-1});

    vector<int> ans;

    while(k>0){
        pair<int, pair<int, int>> temp = pq.top();
        pq.pop();

        int sum = temp.first;
        int x = temp.second.first;
        int y = temp.second.second;

        ans.push_back(sum);

        if(s.find({x-1, y}) == s.end()){
            pq.push({a[x-1] + b[y], {x-1, y}});
            s.insert({x-1, y});
        }
        if(s.find({x, y-1}) == s.end()){
            pq.push({a[x] + b[y-1], {x, y-1}});
            s.insert({x, y-1});
        }
        k--;
    }
    return ans;
}