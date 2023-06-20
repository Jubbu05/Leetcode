class Solution
{
public:
    string removeDuplicates(string s, int k)
    {
        int n = s.length();
        vector<pair<char, int>> st;// {element, count}

        for(auto c : s){
            if(st.size() == 0 || st.back().first != c){
                st.push_back({c, 1});
            }else{
                //match with the element so increase the count
                st.back().second++;
            }

            if(st.back().second == k){
                st.pop_back(); //delete element
            }
        }
        string ans = "";
        for(auto p : st){
            int count = p.second;
            while(count--){
                ans += p.first;
            }
        }
        return ans;
    }
};