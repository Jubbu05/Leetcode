class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dept[], int n)
    {
        sort(arr, arr+n);
        sort(dept, dept+n);
        
        int plat_needed=1, res=1, i=1, j=0;
        
        while(i<n && j<n){
            if(arr[i] <= dept[j]){ //one more platform needed
                plat_needed++;
                i++;
            }
            else if(arr[i] > dept[j]){
                plat_needed--;
                j++;
            }
            res = max(res, plat_needed);
        }
        return res;
    }
};