class Solution{
  public:
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        for(int i=0; i<n; i++){
            if(arr[i] == 0){
                arr[i] = -1;
            }
        }
        unordered_map<int, int> mp;
        int count=0;
        int sum=0;
        
        for(int i=0; i<n; i++){
            sum += arr[i];
            
            if(sum == 0) count++;
            
            if(mp.find(sum) != mp.end()){
                count += mp[sum];
            }
            mp[sum]++;
        }
        return count;
    }
};