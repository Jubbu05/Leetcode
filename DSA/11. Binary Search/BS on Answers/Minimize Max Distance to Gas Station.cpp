#include <bits/stdc++.h>
long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);

    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        long double maxSection = -1;
        int maxInd = -1;
        for (int i = 0; i < n - 1; i++)
        {
            long double diff = arr[i + 1] - arr[i];
            long double section = diff / (long double)(howMany[i] + 1);
            if (section > maxSection)
            {
                maxSection = section;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }

    long double maxAns = -1;
    for (int i = 0; i < n - 1; i++)
    {
        long double diff = arr[i + 1] - arr[i];
        long double section = diff / (long double)(howMany[i] + 1);
        maxAns = max(maxAns, section);
    }
    return maxAns;
}

//-----------------------------------------------------------------------------------------

//TC - O(NlogN + KlogN)
//SC - O(N-1)

#include <bits/stdc++.h>
long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    for (int i = 0; i < n - 1; i++)
    {
        long double diff = arr[i + 1] - arr[i];
        pq.push({diff, i});
    }

    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        auto top = pq.top();
        pq.pop();
        int ind = top.second;
        howMany[ind]++;
        long double initialdiff = arr[ind + 1] - arr[ind];
        long double newdiff = initialdiff / (long double)(howMany[ind] + 1);
        pq.push({newdiff, ind});
    }

    return pq.top().first;
}

//-----------------------------------------------------------------------------------------

//TC - O(NlogN + KlogN)
//SC - O(N-1)
#include <bits/stdc++.h>
int NumberOfGasStations(vector<int> &arr, long double dist)
{
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int numberInBetween = ((arr[i] - arr[i - 1]) / dist);
        if (((arr[i] - arr[i - 1]) / dist) == numberInBetween * dist) // its an exact division
        { 
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    long double low = 0;
    long double high = 0;

    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    long double diff = 1e-6;

    while (high - low > diff)
    {
        long double mid = (low + high) / 2.0;
        int cnt = NumberOfGasStations(arr, mid);
        if (cnt > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}