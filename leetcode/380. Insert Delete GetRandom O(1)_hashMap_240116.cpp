class RandomizedSet {
    vector<int> v;
    unordered_map<int, int> cache;
public:
    RandomizedSet() {}
    
    bool insert(int val) {
        if(cache.count(val)) return false;
        v.push_back(val);
        cache[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!cache.count(val)) return false;
        v[cache[val]] = v.back();
        cache[v.back()] = cache[val];
        v.pop_back();
        cache.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */