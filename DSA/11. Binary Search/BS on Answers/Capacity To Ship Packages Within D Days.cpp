class Solution {
public:
    int daysReq(vector<int>& weights, int capacity){
        int days = 1;
        int sum = 0;
        for(int i = 0; i < weights.size(); i++){
            sum += weights[i];
            if(sum > capacity){
                days++;
                sum = weights[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *(max_element(weights.begin(), weights.end()));
        //sum of all elements                                 0->initial sum
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(daysReq(weights, mid) <= days){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};