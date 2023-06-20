class Solution {
public:
    // only works for positive input
//     double myPow(double x, int n) {
//       double ans = 1.0;
//       if (n < 0) n = -1 * n;
//       for (int i = 0; i < n; i++) {
//         ans = ans * x;
//       }
//     }
    
//------------------------------------------------------------------------------------    
    // for negative do 1/ans
    // [n % 2 == 0] x*x & n/2
    // [n % 2 == 1] ans=ans*x & n=n-1
    
    double myPow(double x, int n) {
      double ans = 1.0;
      long long nn = n;
      if (nn < 0) nn = -1 * nn;
      while (nn>0) {
        if (nn % 2 == 1) {
          ans = ans * x;
          nn = nn - 1;
        } else {
          x = x * x;
          nn = nn / 2;
        }
      }
      if (n < 0) ans = (double)(1.0) / (double)(ans);
      return ans;
    }
};