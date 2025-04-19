class Solution {
    int solve(int idx, unordered_set<string>& set, string& s){
        int n = s.size();
        if(idx == n) return set.size();
        
        int ret = 0;
        for(int length = 1; idx + length<=n; ++length){
            string sub = s.substr(idx, length);
            if(!set.count(sub)){
                set.insert(sub);
                ret = max(ret, solve(idx + length, set, s));
                set.erase(sub);
            }
        }
        return ret;
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> set;
        return solve(0, set, s);
    }
};