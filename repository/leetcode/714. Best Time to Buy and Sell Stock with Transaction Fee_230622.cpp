class Solution {
    
    int dp[50001][2];

    int _fee, n;

    int solve(vector<int>& prices, int idx, int hold){
        if(idx == n) return 0;

        int& ret = dp[idx][hold];

        if(ret != -1) return ret;

        // 과거에 주식을 구매하고 있는 상태면
        if(hold)
            // 팔거나 계속 유지하거나
            ret = max(prices[idx] - _fee + solve(prices, idx + 1, 0), solve(prices, idx + 1, 1));
        else
            // 구매하거나 그냥 지나가거나
            ret = max(-prices[idx] + solve(prices, idx + 1, 1), solve(prices, idx + 1, 0));
        
        return ret;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp, -1, sizeof(dp));

        _fee = fee; n = prices.size();

        return solve(prices, 0, 0);
    }
};