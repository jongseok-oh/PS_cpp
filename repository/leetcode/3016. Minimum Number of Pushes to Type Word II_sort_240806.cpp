class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> cnts;
        for(char c:word) ++cnts[c];

        vector<pair<char, int>> vec;
        vec.assign(cnts.begin(), cnts.end());
        sort(vec.begin(), vec.end(), [](auto& a, auto& b){
            return a.second > b.second;
        });
        
        int ret = 0;
        for(int i = 0, mult = 0; i<vec.size(); ++i){
            if(i % 8 == 0) ++mult;
            auto [_, cnt] = vec[i];
            ret += mult * cnt;
        }

        return ret;
    }
};