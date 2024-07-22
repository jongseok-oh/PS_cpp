class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        vector<pair<string, int>> vec(n);

        for(int i = 0; i<n; ++i){
            auto& [name, height] = vec[i];
            name = names[i];
            height = heights[i];
        }

        sort(vec.begin(), vec.end(), [&](auto& a, auto& b){
            return a.second > b.second;
        });

        vector<string> ret(n);
        for(int i = 0; i<n; ++i) ret[i] = vec[i].first;
        return ret;
    }
};