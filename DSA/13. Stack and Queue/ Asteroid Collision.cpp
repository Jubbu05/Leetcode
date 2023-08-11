class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        stack<int> st;

        for (auto x : asteroids){
            while(!st.empty() && st.top() > 0 && x < 0 && st.top() < abs(x)){
                st.pop();
            }
            if(st.empty() || st.top() < 0 || x > 0){
                st.push(x);
            }
            else if(st.top() == abs(x)){
                st.pop();
            }
        }
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};