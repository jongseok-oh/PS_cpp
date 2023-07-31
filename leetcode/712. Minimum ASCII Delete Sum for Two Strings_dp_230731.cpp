class Solution {
    int totalSum = 0;
    int n,m;
    int dp[1000][1000];

    int solve(int i, int j, string& s1, string& s2){
        if(i >= n || j >= m) return 0;

        int& ret = dp[i][j];

        if(ret != -1) return ret;

        ret = 0;

        if(s1[i] == s2[j]) ret = solve(i + 1, j + 1, s1, s2) + s1[i];

        ret = max(ret, solve(i + 1, j, s1, s2));
        ret = max(ret, solve(i, j + 1, s1, s2));

        return ret;
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        for(auto& c: s1) totalSum += c;
        for(auto& c: s2) totalSum += c;

        n = s1.size(), m = s2.size();
        
        memset(dp, -1, sizeof dp);
        return totalSum - solve(0,0,s1,s2) * 2;
    }
};