// The tolower() function in C++ converts a given character to lowercase. 
// isalnum - Checks whether c is either a decimal digit or an uppercase or lowercase letter.
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int left = 0;
        int right = n-1;
        while(left < right){
            if(!isalnum(s[left])){
                left++;
            }
            else if(!isalnum(s[right])){
                right--;
            }
            else if(tolower(s[left])!=tolower(s[right])){
                return false;
            }
            else{
                left++;
                right--;
            }
        }
        return true;
    }
};