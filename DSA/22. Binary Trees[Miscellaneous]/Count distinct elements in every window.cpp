class Solution{
  public:
    vector <int> countDistinct (int A[], int n, int k)
    {
        vector<int> ans;
        unordered_map<int,int> mp;
        int j=0,i=0;
        while(j<n)
        {
           mp[A[j]]++;
            
            if(j-i+1==k)
            {
                ans.push_back(mp.size());
                
                mp[A[i]]--;
                if(mp[A[i]]==0) mp.erase(A[i]);
                
                i++;
            }
            j++;
        }
        return ans;
    }
};