class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ret = -1;
        int n = values.size();
        for(int i = 0; i<n; ++i){
            int s = max(i - values[i], 0);
            int e = min(n, i + values[i] + 1);
            for(int j = s; j<e; ++j){
                if(j == i) continue;
                ret = max(ret, values[i] + values[j] - abs(j - i));
            }
        }
        return ret;
    }
};