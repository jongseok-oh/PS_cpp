class Solution {
public:
    bool dp[1000][1000];

    string longestPalindrome(string s) {
        int n = s.size();

        for(int i = 0; i<n; i++) dp[i][i] = true;

        int start = 0, len = 1;

        for(int j = 0; j<n; j++) for(int i = j - 1; i>=0; i--){
            dp[i][j] = ((i == j-1 || dp[i+1][j-1]) && s[i] == s[j]);
            if(dp[i][j]){
                if(len < j - i + 1){
                    start = i; len = j-i+1;
                }
            }
        }
        return s.substr(start, len);
    }
};