// K = longest size string
// O(NKlogK)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        int n = strs.size();
        string temp;
        
        for(int i=0; i<n; i++){
            temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            mp[strs[i]].push_back(temp);
        }
        vector<vector<string>> res;
        for(auto it=mp.begin(); it!= mp.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};