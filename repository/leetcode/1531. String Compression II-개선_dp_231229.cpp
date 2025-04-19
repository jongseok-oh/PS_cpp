class Solution {
    // dp[i][k] = substring(i)에 대해
    // k번 삭제해서 얻을 수 있는
    // 최소 문자열 길이
    int dp[100][101];

    int solve(int idx, int k, string& s){
        int n = s.size();
        // 남은 k로 문자를 다 지울 수 있으면
        if(n - idx <= k) return 0;
        int& ret = dp[idx][k];
        if(ret != -1) return ret;

        // 문자를 하나 지우고 넘어가기
        // a10 -> a9와 같이 감소되는 부분 확인
        ret = k?solve(idx + 1, k-1, s):1001;

        int cnt = 1;
        for(int i = idx + 1; i<=n; ++i){
            ret = min(ret, 1 + ((cnt>99)?3:(cnt>9)?2:(cnt>1)?1:0) + solve(i, k, s));

            if(i<n && s[idx] == s[i]) ++cnt;
            else if(--k < 0) break;;
        }
        return ret;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof dp);
        return solve(0,k,s);
    }
};