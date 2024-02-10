class Solution {
    bool dp[1000][1000];
public:
    int countSubstrings(string s) {
        int n = s.size();

        int ret = n;
        for(int i = 0; i<n-1; ++i) {
            dp[i][i] = true;
            if(s[i] == s[i + 1]){
                dp[i][i+1] = true;
                ++ret;
            }
        }
        dp[n-1][n-1] = true;

        for(int j = 2; j<n; ++j){
            for(int i = 0; i + j<n; ++i){
                if(dp[i+1][i+j-1] && s[i] == s[i+j]){
                    dp[i][i+j] = true; ++ret;
                }
            }
        }

        return ret;
    }
};