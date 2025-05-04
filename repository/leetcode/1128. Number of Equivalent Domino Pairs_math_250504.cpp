class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> cnt;
        for(auto& d : dominoes){
            if(d[0] > d[1]) swap(d[0], d[1]);
            ++cnt[d[0]*10 + d[1]];
        }
        int ret = 0;
        for(auto& [_, v] : cnt){
            ret += v * (v -1)/2;
        }

        return ret;
    }
};