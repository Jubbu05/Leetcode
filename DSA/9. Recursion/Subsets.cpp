class Solution {
public:
    void helper(int i, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }
        //to take ith element
        temp.push_back(nums[i]);
        helper(i+1, nums, temp, ans);
        temp.pop_back();
        
        //to skip ith element
        helper(i+1, nums, temp, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(0, nums, temp, ans);

        return ans;
    }
};