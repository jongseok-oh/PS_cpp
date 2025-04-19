class Solution {
    int dp[26];
public:
    int longestIdealString(string s, int k) {
        int ret = -1;
        for(char c : s){
            int idx = c-'a', temp = dp[idx];
            for(int i = max(idx-k, 0), j = min(idx+k, 25); i<=j; ++i){
                temp = max(temp, dp[i] + 1);
            }
            dp[idx] = temp;
            ret = max(ret, dp[idx]);
        }
        return ret;
    }
};