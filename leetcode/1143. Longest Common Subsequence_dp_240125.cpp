class Solution {
    int dp[1000][1000];
    int n, m;
    int solve(int i, int j, string& text1, string& text2){
        if(i == n|| j == m) return 0;
        int&ret = dp[i][j];
        if(ret != -1) return ret;

        ret = (text1[i]==text2[j]) + solve(i + 1, j + 1, text1, text2);
        ret = max(ret, solve(i + 1, j, text1, text2));
        ret = max(ret, solve(i, j + 1, text1, text2));

        return ret;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof dp);
        n = text1.size(), m = text2.size();
        return solve(0, 0, text1, text2);
    }
};