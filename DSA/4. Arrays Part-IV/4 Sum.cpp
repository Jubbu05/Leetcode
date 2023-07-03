class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        long long int n = nums.size();
        vector<vector<int>> output;
        if(n<4){
            return output;
        }
        sort(nums.begin(), nums.end());

        //loop for moving a
        for(int i=0; i<n-3; i++){
            //loop for moving b
            for(int j=i+1; j<n-2; j++){
                // a + b + c + d = target
                // c + d = target - (a + b)
                long long int leftsum= 1LL*target-(1LL*nums[i]+1LL*nums[j]);

                int start = j+1;
                int end = n-1;

                while(start<end){
                    if(nums[start]+nums[end]==leftsum){
                        ans.push_back({nums[i], nums[j], nums[start], nums[end]});
                        while(start<end && nums[start]==nums[start+1]) start++; //to skip duplicate c
                        while(start<end && nums[end]==nums[end-1]) end--; //to skip duplicate d
                        start++;
                        end--;
                    }
                    else if(nums[start]+nums[end]<leftsum){
                        start++;
                    }
                    else{
                        end--;
                    }
                }
                while(j+1<n && nums[j]==nums[j+1]) j++;  //to skp duplicate b
            }
            while(i+1<n && nums[i]==nums[i+1]) i++;  //to skip duplicate a
        }
        return ans;
    }
};