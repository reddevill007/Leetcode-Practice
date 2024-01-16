class RandomizedSet {
    vector<int> randSet;
    unordered_map<int, int> mp;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end()) {
            return false;
        }
        randSet.push_back(val);
        mp[val] = randSet.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end()) {
            return false;
        }

        auto it = mp.find(val);
        randSet[it->second] = randSet.back();
        randSet.pop_back();
        mp[randSet[it->second]] = it->second;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        return randSet[rand() % randSet.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */