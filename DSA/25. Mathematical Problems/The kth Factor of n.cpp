class Solution
{
public:
    int kthFactor(int n, int k)
    {
        vector<int> fact;

        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                fact.push_back(i);
            }
        }
        return (fact.size() < k) ? -1 : fact[k - 1];
    }
};

class Solution
{
public:
    int kthFactor(int n, int k)
    {
        int cnt = 0;

        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
            {
                cnt++;
            }
            if (cnt == k)
            {
                return i;
            }
        }
        return -1;
    }
};