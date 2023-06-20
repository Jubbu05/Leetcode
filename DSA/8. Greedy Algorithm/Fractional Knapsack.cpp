class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double, int>> v;
        for(int i=0; i<n; i++){
            double x = arr[i].value*1.0/arr[i].weight*1.0;
            v.push_back({x, i});
        }
        sort(v.begin(), v.end(), greater<pair<double, int>>());
        int weight=0;
        double ans=0;
        for(int i=0; i<v.size(); i++){
            if(weight+arr[v[i].second].weight<=W){
                weight+=arr[v[i].second].weight;
                ans+=arr[v[i].second].value;
            }
            else{
                int rem = W-weight;
                ans+=rem*v[i].first;
                break;
            }
        }
        return ans;
    }
        
};
