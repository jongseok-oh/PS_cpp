class Solution {
    int n;
    // dp[i][j] 앞으로 i명을 뽑는데
    // 지금 쿠키가 j만큼 팔렸을 때
    int dp[9][1<<8];

    int calcSum(int visit, vector<int>& cookies){
        int sum = 0;
        for(int i = 0; i<n; i++)
            if(visit & (1<<i)) sum += cookies[i];
        return sum;
    }

    int solve(int k, int visit,vector<int>& cookies){
        int& ret = dp[k][visit];

        if(ret != -1) return ret;

        if(k == 1){
            // 앞에 애들이 고르고 남은거
            int myCookie = (((1<<n) - 1) ^ visit);
            int sum = calcSum(myCookie, cookies);
            return ret = sum;
        }

        ret = 1e9;

        for(int i = 1; i<(1<<n); i++)
            if(!(visit & (i)))
                ret = min(ret, max(calcSum(i, cookies), solve(k-1, visit| i, cookies)));
        
        return ret;
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        memset(dp, -1, sizeof(dp));
        return solve(k, 0, cookies);
    }
};