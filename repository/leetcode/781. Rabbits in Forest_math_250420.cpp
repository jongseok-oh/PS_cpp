class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> cnt(1001);
        for(int ans : answers) ++cnt[ans];

        int ret = 0;
        for(int i = 0; i<1001; ++i){
            if(cnt[i]){
                ret += cnt[i] > i?(cnt[i] + i)/(i + 1) * (i + 1):i+1;
            }
        }

        return ret;
    }
};