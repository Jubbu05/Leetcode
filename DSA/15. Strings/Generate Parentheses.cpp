// Condition
// opening_count < n
// closing_count < opening_count
// do until opening_count == closing_count == n

class Solution {
public:
    
    void solver(vector<string>& ans, int n, int opening_count, int closing_count, string s){
        if(opening_count == n && closing_count ==n){
            ans.push_back(s);
            return;
        }
        if(opening_count < n) solver(ans, n, opening_count + 1, closing_count, s + "(");
        if(closing_count < opening_count) solver(ans, n, opening_count, closing_count + 1, s + ")");   
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int opening_count = 0, closing_count = 0;
        solver(ans, n, opening_count, closing_count, "");
        return ans;
    }
};