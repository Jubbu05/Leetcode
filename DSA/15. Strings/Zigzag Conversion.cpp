// 0 -> down
// 1 -> up
// PAYPALISHIRING
//vector<string> ans(3) ->
// i=0 P   A   H   N
// i=1 A P L S I I G
// i=2 Y   I   R
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        vector<string> ans(numRows, "");

        bool flag = 0;
        int i = 0;
        for(auto ch : s){
            ans[i] += ch;

            if(i==0 || i==numRows-1){ //change the direction
                flag = !flag;
            }
            if(flag == 1){
                i += 1;
            }
            else{
                i -= 1;
            }
        }
        string zigzag = "";
        for(auto it : ans){
            zigzag += it;
        }
        return zigzag;
    }
};