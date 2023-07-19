class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size(); // extract the size of array
        if(n == 0) return 0; // if length of array is zero, then from here simply return 0
        sort(arr.begin(), arr.end());
        int mxLen = 0, currLen = 1;
        
        for(int i = 1; i < n; i++){
            if(arr[i] == arr[i - 1] + 1) // this is the part of consecutive sequence
            {
                currLen++; // increase the curr Length by 1
            }
            else if(arr[i] != arr[i - 1]) // but if it is not equal
            {
                mxLen = max(mxLen, currLen); // update our mxLen 
                currLen = 1; // and reset the currLen with 1
            }
        }
        mxLen = max(mxLen, currLen); // update our mxLen 
        return mxLen; // Finally return mxLen
    }
};

//------------------------------------------------------------------------------------------------

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0; 
        set<int> s;
        int maxlen = 1;

        for(auto it:nums){
            s.insert(it);
        }

        for(int i=0; i<n; i++){
            int curr_ele = nums[i];
            int prev_ele = curr_ele -1;
            int cnt=0;
            if(s.find(prev_ele)==s.end()){ //can't find previous element in list so it can be the start of chain
                //start chain it can be the first element of the chain
                while(s.find(curr_ele) != s.end()){
                    curr_ele += 1;
                    cnt++;
                }
            }
            maxlen = max(maxlen,cnt);
        }
        return maxlen;
    }
};