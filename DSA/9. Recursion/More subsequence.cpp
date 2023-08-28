void solve(string &a, int index, int &n, int &cnt){
    if(index==n){
        cnt++;
        return;
    }
    solve(a, index+1, n, cnt);

    while(index+1<n && a[index]==a[index+1]) index++;
    solve(a, index+1, n, cnt);
}

string moreSubsequence(int n, int m, string a, string b)
{
    string a1 = a, b1 = b;
    sort(a.begin(), a.end());    
    sort(b.begin(), b.end());

    int cnt1=0, cnt2=0;
    solve(a, 0, n, cnt1);
    solve(b, 0, m, cnt2);
    return cnt1>=cnt2 ? a1 : b1; 
}