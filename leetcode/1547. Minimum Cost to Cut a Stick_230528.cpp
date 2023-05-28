class Solution {
    int m;
    int dp[102][102];

    int solve(int left, int right, vector<int>& cuts){
        if(left + 1 == right) return 0;

        int& ret = dp[left + 1][right + 1];

        if(ret != -1) return ret;
        ret = 1e9;

        int cost = cuts[right] - (left == -1?0:cuts[left]);
        for(int i = left + 1; i< right; i++){
            ret = min(ret, cost + solve(left, i, cuts) + solve(i, right, cuts));
        }
        return ret;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        m = cuts.size();
        cuts.push_back(n);

        memset(dp, -1, sizeof(dp));
        return solve(-1, m, cuts);
    }
};