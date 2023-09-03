#include <bits/stdc++.h>
int subarraysWithSumK(vector<int> a, int k) {
    int n = a.size(); 
    int xr = 0;
    map<int, int> mpp;
    mpp[0] = 1;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        xr = xr ^ a[i];
        int rem= xr ^ k;
        cnt += mpp[rem];
        mpp[xr]++;
    }
    return cnt;
}