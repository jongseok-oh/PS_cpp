class Solution {
    const int MOD = 1e9 + 7;
public:
    int lengthAfterTransformations(string s, int t) {
        vector<vector<int>> cnt(26, vector<int>(2));
        for(char c : s) ++cnt[c-'a'][0];

        int idx = 0;
        while(t--){
            cnt[0][idx^1] = 0;
            for(int i = 0; i<25; ++i){
                cnt[i+1][idx^1] = cnt[i][idx];
            }
            cnt[0][idx^1] = (cnt[0][idx^1] + cnt[25][idx]) % MOD;
            cnt[1][idx^1] = (cnt[1][idx^1] + cnt[25][idx]) % MOD;
            idx ^= 1;
        }

        int ret = 0;
        for(int i = 0; i<26; ++i){
            ret = (ret + cnt[i][idx]) % MOD;
        }

        return ret;
    }
};