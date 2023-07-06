class Solution {
public:
    int reverse(int x) {
        if(x >= 2147483647 || x <= -2147483648) return 0; //32 bit
        long long res = 0;
        if(x>0){
            while(x>0){
                int digit = x%10;
                res = res*10 + digit;
                if(res >= 2147483647 || res <= -2147483648) return 0;
                x /= 10;
            }
        }
        else{
            x *= -1;
            while(x>0){
                int digit = x%10;
                res = res*10 + digit;
                if(res >= 2147483647 || res <= -2147483648) return 0;
                x /= 10;
            }
            res *= -1;
        }
        return int(res);
    }
};