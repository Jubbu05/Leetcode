class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> mpp(256, -1);
        int left = 0,
        right = 0;

        int n = s.length();
        int len = 0;

        while(right<n){             // update only when in range of l and r
            if(mpp[s[right]] != -1) left = max(mpp[s[right]]+1, left); // update left choosing max of last seen index+1 and current left

            mpp[s[right]] = right; //last seen index

            len = max(len, right-left+1);
            right++;
        }
        return  len;
    }
};