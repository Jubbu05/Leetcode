// https://practice.geeksforgeeks.org/problems/minimum-swaps/1
class Solution
{
public:
    // Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end()); // sort according to value
        int swaps = 0;
        for (int i = 0; i < n; i++)
        {
            pair<int, int> p = v[i];
            int value = p.first;
            int index = p.second;

            // 2,0  8,1  5,2  4,3

            // 2,0  4,3  5,2  8,1
            // i=0    1    2    3

            // if  i == index then index is at correct position no need to swap

            if (i != index)
            {
                swap(v[i], v[index]);
                swaps++;
                i--; // we need to check i again if the swapped element is at correct position or not
            }
        }
        return swaps;
    }
};