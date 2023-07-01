class Solution
{
public:
    long long int floorSqrt(long long int x)
    {
        long long int low = 1;
        long long int high = x;
        long long int ans = -1;
        while (low <= high)
        {
            long long mid = (low + high) / 2;
            long long msq = mid * mid;
            
            if (msq <= x)
            {
                ans = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        return ans;
    }
};