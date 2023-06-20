class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    // int celebrity(vector<vector<int> >& M, int n) 
    // {
    //     // code here 
    //     int in[n] = {0};
    //     int out[n] = {0};
        
    //     for(int i=0; i<n; i++){
    //         for(int j=0; j<n; j++){
    //             if(M[i][j]==1){
    //                 in[j]++;
    //                 out[i]++;
    //             }
    //         }
    //     }
    //     for(int i=0; i<n; i++){
    //         if(in[i]==n-1 && out[i]==0){
    //             return i;
    //         }
    //     }
    //     return -1;
    // }
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        int celebrity = 0;
        for(int i=1; i<n; i++){
            if(M[celebrity][i]==1){
                //celebrity knows i so we update our celebrity
                celebrity=i;
            }
        }
        
        for(int i=0; i<n; i++){
                                //if celebrity knows i he can't be a celebrity or if i doesn't know celebrity he can't 
            if(i!=celebrity && (M[celebrity][i]==1 || M[i][celebrity]==0)) return -1;
        }
        
        return celebrity;
    }
}: