class Solution {
    int dp[50];

    int solve(int idx, string& s, vector<string>& dictionary){
        int n = s.size();

        if(idx == n) return 0;

        int& ret = dp[idx];

        if(ret != -1) return ret;

        ret = 1 + solve(idx+1, s, dictionary);

        for(auto& ds: dictionary){
            int m = ds.size();
            if(idx + m > n) continue;

            if(s.substr(idx, m) == ds)
                ret = min(ret, solve(idx+m,s,dictionary));
        }

        return ret;
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp, -1, sizeof dp);

        return solve(0, s, dictionary);
    }
};