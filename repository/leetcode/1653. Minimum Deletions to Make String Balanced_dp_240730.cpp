class Solution {
    int dp[100000][2];
    int solve(int idx, int temp, string& s){
        if(idx == s.size()) return 0;
        int& ret = dp[idx][temp];
        if(ret != -1) return dp[idx][temp];
        ret = 1e9;
        
        if(temp == 0){
            if(s[idx] == 'a') ret = solve(idx + 1, 0, s);
            else ret = min(solve(idx + 1, 0, s) + 1, solve(idx + 1, 1, s));
        }else{
            ret = solve(idx + 1, 1, s) + (s[idx]=='a');
        }
        return ret;
    }
public:
    int minimumDeletions(string s) {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, s);
    }
};