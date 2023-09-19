class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(auto it : nums){
            mp[it]++;
            if(mp[it] > 1){
                return true;
            }
        }
        return false;
    }
};

class Solution {
   	public:
   	bool containsDuplicate(vector<int>& nums) {
   		set<int> a;
   		for(auto x:nums)
   		a.insert(x);
   		return (a.size()!=nums.size());
   }
};


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=1; i<n; i++){
             if(nums[i] == nums[i-1]) return true;   
        }
        return false;
    }
};
