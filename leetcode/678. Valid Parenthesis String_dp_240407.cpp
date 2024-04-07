class Solution {
    int dp[100][101];

    bool solve(int idx, int cnt, string& s){
        if(idx == s.size()) {return cnt == 0;}
        if(cnt < 0) { return 0;}
        int& ret = dp[idx][cnt];
        if(ret != -1) return ret;

        if(s[idx] == '('){
            return ret = solve(idx+1, cnt + 1, s);
        }else if(s[idx] == ')'){
            return ret = solve(idx+1, cnt - 1, s);
        }else{
            if(solve(idx+1, cnt + 1, s) == 1) return ret = 1;
            if(solve(idx+1, cnt - 1, s) == 1) return ret = 1;
            if(solve(idx+1, cnt, s) == 1) return ret = 1;
        }
        return ret = 0;
    }
public:
    bool checkValidString(string s) {
        memset(dp, -1, sizeof dp);
        return solve(0, 0, s);
    }
};