class Solution {
    int dp[100][100];
    int solve(int i, int j, string& s){
        if(i == j) return 1;
        int& ret = dp[i][j];
        if(ret) return ret;

        if(s[j-1] == s[j]) return ret = solve(i, j -1, s);
        if(s[i] == s[j] ||s[i] == s[i+1]) return ret = solve(i + 1, j, s);
        
        ret = 1 + solve(i+1, j, s);

        for(int k = i+1; k<j; ++k){
            if(s[i] == s[k]){
                ret = min(ret, solve(i, k, s) + solve(k+1,j, s));
            }
        }
        return ret;
    }
public:
    int strangePrinter(string s) {
        return solve(0, s.size()-1, s);
    }
};