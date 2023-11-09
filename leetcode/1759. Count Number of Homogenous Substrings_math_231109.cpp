class Solution {
    const int MOD = 1e9 + 7;
public:
    int countHomogenous(string s) {
        int n = s.size();
        int ret = 0, cnt = 1;

        for(int i = 0; i<n; ++i){
            if(i == n-1 || s[i + 1] != s[i]){
                ret = ((1LL + cnt) * cnt/2 + ret)%MOD;
                cnt = 1;
            }else ++cnt;
        }

        return ret;
    }
};