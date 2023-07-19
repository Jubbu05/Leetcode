class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int count = 0;
        for(int i=0; i<n; i++){
            if(arr[i]<=k){
                count++;
            }
        }

        // number of elements greater than k in first window
        int bad = 0;
        for(int i=0; i<count; i++){
            if(arr[i]>k){
                bad++;
            }
        }
        
        int ans = bad;
        // sliding window
        // window size = count
        for(int i=0, j=count; j<n; i++,j++){

            // remove element from previous window
            // decrease bad if it is greater than k
            if(arr[i]>k){
                bad--;
            }

            // add element from current window
            // increase bad if it is greater than k
            if(arr[j]>k){
                bad++;
            }
            ans = min(ans,bad);
        }
        return ans;
    }
};