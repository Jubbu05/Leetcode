// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> t; 
        
//         for(auto i:s) {
//             if(i == '(' || i =='{' || i == '[') t.push(i);
//             else{
//                 if(t.empty() || (t.top() == '(' && i != ')') || (t.top() == '{' && i != '}') || (t.top() == '[' && i != ']')) return false;
                
//                 t.pop();
//             }
//         }
//         return t.empty();
//     }
// };

class Solution {
public:
    bool isValid(string s) {
        stack <char> st;
        
        int len = s.length();
        for (int i = 0; i<len ; i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else if(s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if(st.empty())
                    return false;
                else if(s[i] == ')' && st.top() != '(')
                    return false;
                else if(s[i] == '}' && st.top() != '{')
                    return false;
                else if(s[i] == ']' && st.top() != '[')
                    return false;
                else 
                    st.pop();
            }
        }
        if(st.empty())
            return true;
        else
            return false;
    }
};`