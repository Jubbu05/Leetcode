class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();

        for(int i=0; i<n; i++){
            s += s[0];
            s.erase(0,1);

            if(s == goal){
                return true;
            }
        }
        return false;
    }
};