class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        
        if(n==1 && m==1) return 0;
        sort(a.begin(), a.end());
        long long min = INT_MAX;
        for(int i=0; i+m-1<n; i++){
            long long diff = a[i+m-1] - a[i];
            if(diff<min){
                min = diff;
            }
        }
        return min;
    }   
};