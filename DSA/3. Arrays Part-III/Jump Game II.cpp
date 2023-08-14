class Solution {
public:
    int jump(vector<int>& arr) {
        int n=arr.size();
        int farthest=0, currReach=0,  jumps=0;
        for(int i=0; i<n-1; i++){
            farthest = max(farthest, arr[i]+i);
            if(i == currReach){                
                currReach = farthest;
                jumps++;
            }
        }
        return jumps;
    }
};