class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        unordered_map<int, int> m;
        
        for(int& num: nums) ++m[num];

        vector<pair<int,int>> vec(m.begin(), m.end());
        sort(vec.rbegin(), vec.rend());

        int ret = 0, temp = 0;
        for(int i = 0; i<vec.size()-1; ++i){
            temp += vec[i].second;
            ret += temp;
        }

        return ret;
    }
};