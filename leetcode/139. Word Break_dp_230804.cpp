class Solution {
    int dp[300];

    int solve(int start, string& s, vector<string>& wordDict){
        if(start >= s.size()) return 1;

        int& ret = dp[start];

        if(ret != -1) return ret;

        ret = 0;
        for(auto& str: wordDict){
            int tlen = str.size();

            if(start + tlen <= s.size() && s.substr(start, tlen) == str)
                if(solve(start + tlen, s, wordDict))
                    return ret = 1;
        }
        return ret;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof dp);
        return solve(0, s, wordDict);
    }
};