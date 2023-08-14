class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> res; 
        sort(num.begin(), num.end()); 
        int n = num.size();
        // moves for a
        for (int i = 0; i < n-2; i++) {
                //a+b+c=0    
                //b+c=0-a
                int lo = i+1, hi = n-1, sum = 0 - num[i];
                
                while (lo < hi) {
                    if (num[lo] + num[hi] == sum) {
        
                        res.push_back({num[i], num[lo], num[hi]});
                        
                        //to ignore duplicate's
                        while (lo < hi && num[lo] == num[lo+1]) lo++;
                        while (lo < hi && num[hi] == num[hi-1]) hi--;
                        
                        lo++; hi--;
                    } 
                    else if (num[lo] + num[hi] < sum) lo++;
                    else hi--;
            }
            while(i+1<num.size() && num[i]==num[i+1]) i++;  //to skip duplicate a
        }
        return res;
    }
};
