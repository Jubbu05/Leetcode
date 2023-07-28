class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> presum(n, 0);
        vector<int> sufsum(n, 0);
        presum[0] = nums[0];
        for(int i=1; i<n; i++){
            presum[i] = presum[i-1] + nums[i];
        }
        sufsum[n-1] = nums[n-1];
        for(int i=n-2; i>=0; i--){
            sufsum[i] = sufsum[i+1] + nums[i];
        }

        for(int i=0; i<n; i++){
            if(presum[i] == sufsum[i]){
                return i;
            }
        }
        return -1;
    }
};

//---------------------------------------------------------

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }

        int leftSum = 0;
        int rightSum = sum;

        for(int i=0; i<n; i++){
            rightSum -= nums[i];
            if(leftSum == rightSum){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};