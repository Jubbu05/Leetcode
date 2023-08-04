class Solution {
public:
    void helper(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        int n = nums.size();
        if(i==n){
            ans.push_back(temp);
            return;
        }
        //to take ith element
        temp.push_back(nums[i]);
        helper(i+1, nums, temp, ans);
        temp.pop_back();

        //to skip ith element
        while(i+1<n && arr[i]==arr[i+1]) i++;
        helper(i+1, nums, temp, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        helper(0, nums, temp, ans);

        return ans;
    }
};
