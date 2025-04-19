class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> cache;
        for(int num: nums) ++cache[num];

        vector<int> ret;
        for(auto& [k, v] : cache){
            if(v == 1) {
                ret.push_back(k);
                if(ret.size() == 2) break;
            }
        }
        return ret;
    }
};