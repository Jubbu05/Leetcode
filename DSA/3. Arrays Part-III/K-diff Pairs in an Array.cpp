// We are aware of the fact that for a pair to be counted as an answer , both the elements ( x and x+k ) , need to be in the array.
// So we simply create a map and store the frequency of each element in the map.
// Now we traverse the map and for each element 'x' , we check if 'x+k' exists in the map . If it does , then it means a unique pair can be formed and hence, we increment the answer.

// EDGE CASE :
// The only edge case is the situation wherek=0. If k=0 , instead of finding 'x+k' , we check if the frequency of 'x'>1. If it is , then weincrement the answer .
// Else , we don't increment the answer , as the frequency of x=1 and hence it can't form a pair with itself.
class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        unordered_map<int, int> a;
        for (int i : nums)
            a[i]++;
        int ans = 0;
        for (auto x : a)
        {
            if (k == 0)
            {
                if (x.second > 1)
                    ans++;
            }
            else if (a.find(x.first + k) != a.end())
                ans++;
        }

        return ans;
    }
};