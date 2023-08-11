class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int count=0;
        int sum=0;
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum == k) count++;
            
            if(m.find(sum-k)!=m.end()){
                count=m[sum-k]+count; 
            }
            
            m[sum]++;
        }
        return count;
    }
};

//---------------------------------------------------------

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int count=0;
        int sum=0;
        
        int n=nums.size();
        m[0] = 1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem = sum - k;
            count += m[rem];
            m[sum]++;
        }
        return count;
    }
};