//O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target){
                    ans.push_back(i);
                    ans.push_back(j);
                    return ans;
                }
            }
        }
        return ans;
    }
};

//O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> um;

        for(int i=0; i<nums.size(); i++){
            int ele = nums[i];
            int elefind = target - ele;
            if(um.find(elefind) != um.end()){
                ans.push_back(i);
                ans.push_back(um[elefind]);
                return ans;
            }
            um[ele] = i;
        }
        return ans;
    }
};

//O(nlogn)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> v;
        
        for(int i=0; i<n; i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(), v.end());
        int start = 0, end = n-1;
        while(start<end){
            int sum = v[start].first + v[end].first;
            if(sum == target) 
                return {v[start].second,v[end].second};
            else if(sum>target)
                end--;
            else
                start++;
        }
        return{-1,-1};
    }
};