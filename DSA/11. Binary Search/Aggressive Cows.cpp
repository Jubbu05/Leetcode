bool isPossible(vector<int> &stalls, int n, int cows, int minDist)
{
    int cntCows = 1;
    int lastPlacedCow = stalls[0]; //cow place in first place and cnt is 1
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - lastPlacedCow >= minDist)
        {
            //we can place a cow
            cntCows++;
            lastPlacedCow = stalls[i];
        }
        if (cntCows == cows)
        return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int cows)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = stalls[n - 1] - stalls[0]; //max-min ... max distance
    
    int ans = 0;
    while(low<=high){
        int mid = (low + high) / 2;
        if(isPossible(stalls, n, cows, mid)){
            ans = mid;
            low = mid + 1; //coz we want to find largest min distance
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
}