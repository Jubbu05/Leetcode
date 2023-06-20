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
            helper(ind+1, target - arr[ind], arr, ans, ds); 
            ds.pop_back();
        }
        //not pick
        while(ind+1<arr.size() && arr[ind]==arr[ind+1]) ind++; //to skip duplicates in the array
        helper(ind + 1, target, arr, ans, ds);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        helper(0, target, candidates, ans, ds);
        return ans;
    }
};