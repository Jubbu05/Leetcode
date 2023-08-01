class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {

        if (n == 1 && m == 1)
            return 0;
        sort(a.begin(), a.end());
        long long min = INT_MAX;
        for (int i = 0; i + m - 1 < n; i++) // i + m - 1 is window size
        {
            long long diff = a[i + m - 1] - a[i];
            if (diff < min)
            {
                min = diff;
            }
        }
        return min;
    }
};

class Solution
{
public:
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(), a.end());
        long long mini = INT_MAX;
        long long l = 0, r = m - 1;
        while (r < n)
        {
            long long diff = a[r] - a[l];
            mini = min(mini, diff);
            l++;
            r++;
        }
        return mini;
    }
};