class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        if(n<=1) return 0;
        
        priority_queue<long long ,vector<long long>, greater<long long>> pq(arr, arr+n);
        
        long long sum=0;
        
        while(!pq.empty()){
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            long long temp = first + second;
            sum += temp;
            if(!pq.empty()){
                pq.push(temp);
            }
        }
        return sum;
    }
};