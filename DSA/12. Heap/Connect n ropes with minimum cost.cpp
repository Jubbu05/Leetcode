// Minimum Cost To Connect Sticks

#include <bits/stdc++.h>
long long int minimumCostToConnectSticks(vector<int> &arr)
{
    int n = arr.size();
    if (n <= 1)
        return 0;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (auto it : arr)
    {
        pq.push(it);
    }

    long long sum = 0;

    while (!pq.empty())
    {
        long long first = pq.top();
        pq.pop();
        long long second = pq.top();
        pq.pop();
        long long temp = first + second;
        sum += temp;
        if (!pq.empty())
        {
            pq.push(temp);
        }
    }
    return sum;
}
