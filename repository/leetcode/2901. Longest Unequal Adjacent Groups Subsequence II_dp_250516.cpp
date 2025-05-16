class Solution {
    bool isValid(string& s1, string& s2){
        int n = s1.size(), m = s2.size();
        if(n != m) return false;

        int differentCnt = 0;
        for(int i = 0; i<n; ++i){
            if(s1[i] != s2[i]) ++differentCnt;
        }

        return differentCnt == 1;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = groups.size();

        int start = -1;
        vector<int> dp(n, 1);
        for(int i = n-1; i>=0; --i){
            for(int j = i + 1; j<n; ++j){
                if(groups[i] != groups[j] && isValid(words[i], words[j])){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if(start == -1 || dp[start] < dp[i]){
                start = i;
            }
        }

        vector<string> ret;
        for(int i = start; i<n;){
            ret.emplace_back(words[i]);
            int j = i + 1;
            for(;j<n; ++j){
                if(dp[i] == dp[j] + 1
                && groups[i] != groups[j]
                && isValid(words[i], words[j])) break;
            }
            i = j;
        }

        return ret;
    }
};