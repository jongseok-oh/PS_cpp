class Solution {
    int n;

    int solve(int i, int k, int end, vector<vector<int>>& dp, vector<vector<int>>& events){
        if(i == n || k == 0) return 0;

        if(end >= events[i][0]) return solve(i + 1, k, end, dp, events);

        int& ret = dp[i][k];
        if(ret != -1) return ret;

        return ret = max(
            events[i][2] + solve(i + 1, k -1, events[i][1], dp, events),
            solve(i + 1, k, end, dp, events)
        );
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();

        sort(events.begin(), events.end());

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        return solve(0, k, 0, dp, events);
    }
};