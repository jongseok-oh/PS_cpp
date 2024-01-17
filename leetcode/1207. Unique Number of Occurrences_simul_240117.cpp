class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        unordered_set<int> s;
        
        for(int n: arr) m[n]++;

        for(auto& kv:m){
            if(s.count(kv.second)) return false;
            s.insert(kv.second);
        }

        return true;
    }
};