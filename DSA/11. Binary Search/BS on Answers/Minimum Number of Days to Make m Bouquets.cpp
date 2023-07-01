class Solution
{
public:
    bool possible(vector<int> &bloomDay, int days, int m, int k)
    {
        int cnt = 0;
        int n = bloomDay.size();
        int numberOfBouquets = 0;
        for (int i = 0; i < n; i++)
        {
            if (bloomDay[i] <= days)
            {
                cnt++;
            }
            else
            {
                numberOfBouquets += cnt / k;
                cnt = 0;
            }
        }
        numberOfBouquets += cnt / k;

        if(numberOfBouquets >= m) return true;

        return false;
    }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int low = 1, high = *(max_element(bloomDay.begin(), bloomDay.end()));
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(possible(bloomDay, mid, m, k)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};