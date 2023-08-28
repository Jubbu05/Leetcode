// // length = curr index - index at top
// class Solution {
// public:
//     int longestValidParentheses(string s) {
//         stack<int> st;
//         st.push(-1);
//         int ans = 0;
//         for(int i=0; i<s.length(); i++){
//             if(s[i] == '(')
//                 st.push(i);
//             else
//                 st.pop();
//                 if(!st.empty())
//                     ans = max(ans, i-st.top());
//                 else
//                     st.push(i);
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        int oc = 0;
        int cc = 0;
        int ans = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                oc++;
            }
            else{
                cc++;
            }
            if(oc == cc){
                ans = max(ans, cc*2);
            }
            else if(cc > oc){
                oc = 0;
                cc = 0;
            }
        }
        oc = 0, cc = 0;
        for(int i=n-1; i>=0; i--){
            if(s[i] == '('){
                oc++;
            }
            else{
                cc++;
            }
            if(oc == cc){
                ans = max(ans, oc*2);
            }
            else if(oc > cc){
                oc = 0;
                cc = 0;
            }
        }
        return ans;
    }
};