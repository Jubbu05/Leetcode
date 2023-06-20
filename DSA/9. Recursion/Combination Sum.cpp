class Solution {
public:
    
    void helper(int ind, int target,vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
        if(ind == arr.size()){
            if(target == 0){
             ans.push_back(ds);   
            }
            return;
        }
        //pick up the element
        if(arr[ind] <= target){
            ds.push_back(arr[ind]);
            helper(ind, target - arr[ind], arr, ans, ds); //we can pick multiple so ind is not increased
            ds.pop_back();
        }
        //not pick
        helper(ind + 1, target, arr, ans, ds);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0, target, candidates, ans, ds);
        return ans;
    }
};