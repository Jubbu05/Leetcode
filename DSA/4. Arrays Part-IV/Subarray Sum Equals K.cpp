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
            
            if(m.find(sum)!=m.end()){
                m[sum]++;
            }else{
                m[sum]=1;
            }
            
        }
        
        return count;
    }
};


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int count=0;
        int presum=0;
        
        m[0] = 1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int remove = presum - k;
            count += m[remove];
            m[presum] += 1;
        }
        
        return count;
    }
};