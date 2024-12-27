class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ret = 0;
        int prev = values[0];
        for(int i = 1, n = values.size(); i<n; ++i){
            --prev;
            ret = max(ret, prev + values[i]);
            prev = max(prev, values[i]);
        }
        return ret;
    }
};