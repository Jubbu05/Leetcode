`class Solution
{
public:
    void helper(int idx, int sum, vector<int>& arr, int n, vector<int>& ans){
        if(idx==n){
            ans.push_back(sum);
            return;
        }

        helper(idx+1,sum+arr[idx],arr,n,ans); //pick
        helper(idx+1,sum,arr,n,ans); //not pick
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans;
        helper(0,0,arr,N,ans);
        return ans;
    }
};