class Solution {
public:
    
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            m[nums[i]]++;
        }
        
        unordered_map<int,int>:: iterator p;
        for (p = m.begin(); p != m.end(); p++){
            if (p->second > n/2) return p->first;
        } 
        return 0;
    }
    
//------------------------------------------------------------------------------------
    
// Boyer–Moore majority vote algorithm
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int element = 0;

        for (int num : nums) {
            if (count == 0) {
                element = num;
            }
            if(num==element) count += 1; 
            else count -= 1; 
        }

        return element;
    }
};