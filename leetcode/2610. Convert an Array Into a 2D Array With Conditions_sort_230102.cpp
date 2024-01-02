class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> m;

        for(int& num: nums) ++m[num];
        vector<pair<int, int>> vec(m.begin(), m.end());

        sort(vec.begin(), vec.end(), [&](auto& a, auto& b){
            return a.second > b.second;
        });

        vector<vector<int>> ret;

        int idx = vec.size() - 1;

        while(idx >= 0){
            vector<int> t;
            for(int i = idx; i>=0; --i){
                t.push_back(vec[i].first);
                if(!--vec[i].second) idx = i -1;
            }
            ret.push_back(t);
        }

        return ret;
    }
};