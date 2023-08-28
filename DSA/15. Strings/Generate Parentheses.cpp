// Condition
// opening_count < n
// closing_count < opening_count
// do until opening_count == closing_count == n

class Solution {
public:
    void solve(vector<string>& ans, string temp, int oc, int cc, int n){
        if(oc == n && cc == n){
            ans.push_back(temp);
            return;
        }
        if(oc < n){
            temp.push_back('(');
            solve(ans, temp, oc+1, cc, n);
            temp.pop_back();
        }

        if(cc < oc){
            temp.push_back(')');
            solve(ans, temp, oc, cc+1, n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int oc = 0;
        int cc = 0;
        solve(ans, "", oc, cc, n);

        return ans;
    }
};