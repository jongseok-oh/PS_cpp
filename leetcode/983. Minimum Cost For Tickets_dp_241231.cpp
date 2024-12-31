class Solution {
    const vector<int> day = {1,7,30};
    int solve(int idx, vector<int>& dp, vector<int>& days, vector<int>& costs){
        int n = dp.size();
        if(idx == n) return 0;
        int& ret = dp[idx];
        if(ret != -1) return ret;

        ret = 1e9;
        for(int k = 0; k<3; ++k){
            int j = idx;
            while(j< n && days[j] < days[idx] + day[k]) ++j;
            ret = min(ret, costs[k] + solve(j, dp, days, costs));
        }

        return ret;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return solve(0, dp, days, costs);
    }
};