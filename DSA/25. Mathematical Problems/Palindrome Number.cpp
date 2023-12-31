class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        if(x != 0 and x%10 == 0) return false;
        int rev=0;
        while(x>rev){
            rev = rev*10 + x%10;
            x /= 10;
        }
        if(x == rev) return true;
        if(x == rev/10) return true;
        return false;
    }
};