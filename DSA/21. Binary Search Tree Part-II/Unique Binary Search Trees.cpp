// Catalan number
class Solution {
public:
    int numTrees(int n) {
        int  res = 0;
        if(n==1 || n==0) return 1;
        for(int i=0; i<n; i++){
            res += numTrees(i) * numTrees(n-i-1);
        }
        return res;
    }
};


class Solution {
    int catalan_Number(int n) {
        vector<int> catalan(n+1);
        catalan[0] = catalan[1] = 1;
        
        for(int i=2;i<=n;++i)
        {
            catalan[i] = 0;
            for(int j=0;j<i;++j)
                catalan[i] += catalan[j]*catalan[i-j-1];
        }
        return catalan[n];
    }
public:
    int numTrees(int n) {
        return catalan_Number(n);
    }
};