class Solution {
    // dp[i][j] = 부분 문자열 i ~ j를
    // 만드는데 필요한 프린트 최소 회수
    int dp[100][100];

    int solve(int i, int j, string& s){
        if(i == j) return 1;
        int& ret = dp[i][j];
        if(ret) return ret;

        // 앞 뒤에 연속 된 알파벳을 압축
        if(s[i] == s[j] || s[i] == s[i + 1]) return ret = solve(i + 1, j, s);
        if(s[j] == s[j - 1]) return ret = solve(i, j - 1, s);
        
        // 맨 앞에 알파벳 프린트하고 시작 (뒤에꺼 부어도 됨)
        ret = solve(i + 1, j, s) + 1;

        // 맨 앞의 알파벳 기준으로
        // 끝점이 같은 subString 탐색
        for(int k = i + 1; k<j; k++)
            if(s[i] == s[k]) ret = min(ret, solve(i, k, s) + solve(k + 1, j, s));
        
        return ret;
    }
public:
    int strangePrinter(string s) {
        return solve(0, s.size()-1, s);
    }
};