class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char, char> ms, mt;
        for(int i=0; i<n; i++){
            if(ms.find(s[i]) == ms.end()){
                if(mt.find(t[i]) == mt.end()){
                    ms[s[i]] = t[i];
                    mt[t[i]] = s[i];
                }
                else{
                    return false;
                }
            }
            else{
                if(ms[s[i]] != t[i]){
                    return false;
                }
            }
        }
        return true;
    }
};