#define pb push_back
#define pob pop_back
class RandomizedSet {
public:
    vector<int> ans;
    unordered_map<int,int> mp;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) return false; //checking in the map if already exists or not
        
        ans.pb(val); //inserting the value in the end of the array
        mp[val] = ans.size() - 1; //updating the map with new entry
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) return false; //not present in the map
        auto it = mp.find(val); //find the index it->{key, index}
        ans[it->second] = ans.back(); //go to that index and replace with the last element in the array
        ans.pob(); //remove the last element
        
        mp[ans[it->second]] = it->second; //updating the index in the map
        mp.erase(val); //remove the element from map
        return true;
    }
    
    int getRandom() {
        return ans[rand() % ans.size()];
    }
};