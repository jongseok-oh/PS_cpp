class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));

        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                if(str1[i] == str2[j]){
                    dp[i+1][j+1] = dp[i][j] + 1;
                }else{
                    dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
            }
        }

        int i = n-1, j = m-1;
        string ret = "";
        for(; i>=0 && j>=0;){
            if(str1[i] == str2[j]){
                ret.push_back(str1[i]);
                --i; --j;
            }else if(dp[i][j+1] > dp[i+1][j]){
                ret.push_back(str1[i--]);
            }else{
                ret.push_back(str2[j--]);
            }
        }
        while(i>=0) ret.push_back(str1[i--]);
        while(j>=0) ret.push_back(str2[j--]);

        reverse(ret.begin(), ret.end());
        return ret;
    }
};