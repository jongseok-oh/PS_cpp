class Solution {
    unordered_map<char, int> cnt;
public:
    string frequencySort(string s) {
        for(char c: s) cnt[c]++;

        vector<pair<char, int>> vec;

        vec.insert(vec.end(), cnt.begin(), cnt.end());
        sort(vec.begin(), vec.end(),[&](auto& p1, auto& p2){
            return p1.second > p2.second;
        });

        string ret;

        for(auto& [c, tCnt] :vec){
            for(int j = 0; j<tCnt; ++j) ret.push_back(c);
        }

        return ret;
    }
};