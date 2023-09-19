// TC - O(NlogN) + O(N)
class Solution
{
public:
    int longestConsecutive(vector<int> &arr)
    {
        int n = arr.size(); // extract the size of array
        if (n == 0)
            return 0; // if length of array is zero, then from here simply return 0
        sort(arr.begin(), arr.end());
        int mxLen = 0, currLen = 1;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] == arr[i - 1] + 1) // this is the part of consecutive sequence
            {
                currLen++; // increase the curr Length by 1
            }
            else if (arr[i] != arr[i - 1]) // but if it is not equal
            {
                mxLen = max(mxLen, currLen); // update our mxLen
                currLen = 1;                 // and reset the currLen with 1
            }
        }
        mxLen = max(mxLen, currLen); // update our mxLen
        return mxLen;                // Finally return mxLen
    }
};

//------------------------------------------------------------------------------------------------

// Optimized Approach
// TC - O(N) + O(N) + O(N) = O(3N) = O(N)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        unordered_set<int> s;
        for(auto it : nums){
            s.insert(it);
        }

        int maxi = 1;

        for(auto it : nums){
            int ele = it;
            int prev = it - 1;
            if(s.find(prev) == s.end()){ //can be the start
                int cnt = 0;
                while(s.find(ele) != s.end()){
                    ele++;
                    cnt++;
                }
                maxi = max(maxi, cnt);
            }
        }
        return maxi;
    }
};