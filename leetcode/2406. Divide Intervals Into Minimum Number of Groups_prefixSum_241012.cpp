class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> prefixSum(1e6 + 2);
        int _min = 1e9, _max = -1;
        for(auto& interval : intervals){
            int a = interval[0], b = interval[1];
            _min = min(_min, a);
            _max = max(_max, b);
            ++prefixSum[a];
            --prefixSum[b + 1];
        }
        int ret = -1, cnt = 0;
        for(int i = _min; i<=_max+1; ++i){
            cnt += prefixSum[i];
            ret = max(ret, cnt);
        }

        return ret;
    }
};