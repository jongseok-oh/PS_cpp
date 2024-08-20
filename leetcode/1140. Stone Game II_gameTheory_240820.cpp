class Solution {
    int dp[100][101];
    int solve(int idx, int m, vector<int>& prefixSum){
        int n = prefixSum.size();
        if(idx >= n-1) return 0;
        int& ret = dp[idx][m];
        if(ret != -1) return ret;
        ret = 0;

        for(int x = 1; x<=2*m && idx + x < n; ++x){
            int myStone = prefixSum[idx + x] - prefixSum[idx];
            int enemyStone = solve(idx+x, max(x,m), prefixSum);
            ret = max(ret, myStone + (prefixSum[n-1] - prefixSum[idx+x] - enemyStone));
        }

        return ret;
    }
public:
    int stoneGameII(vector<int>& piles) {
        vector<int> prefixSum(piles.size() + 1);
        for(int i = 0; i<piles.size(); ++i){
            prefixSum[i+1] = prefixSum[i] + piles[i];
        }
        memset(dp, -1, sizeof dp);
        return solve(0,1,prefixSum);
    }
};