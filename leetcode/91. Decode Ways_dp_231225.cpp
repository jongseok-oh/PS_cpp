class Solution {
    int dp[100];
    
    int solve(int idx, string& s){
        if(idx >= s.size()) return 1;
        if(s[idx] == '0') return 0;
        int& ret = dp[idx];
        if(ret != -1) return ret;

        ret = 0;
        ret += solve(idx + 1, s);
        if(s[idx] == '1' && s.size() > idx + 1)
            ret += solve(idx + 2, s);
        if(s[idx] == '2' && s.size() > idx + 1 && s[idx + 1] >= '0' && s[idx + 1] <= '6')
            ret += solve(idx + 2, s);

        return ret;
    }
public:
    int numDecodings(string s) {
        memset(dp, -1, sizeof dp);
        return solve(0,s);
    }
};