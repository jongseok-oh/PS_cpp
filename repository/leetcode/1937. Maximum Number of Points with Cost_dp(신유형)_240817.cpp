class Solution {
    using ll = long long;
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points[0].size();
        vector<ll> dp(m), left(m), right(m);

        for(int i = 0; i<m; ++i) dp[i] = points[0][i];
        for(int j = 1; j<n; ++j){
            left[0] = dp[0];
            for(int i = 1; i<m; ++i){
                left[i] = max(left[i-1] - 1, dp[i]);
            }
            right[m-1] = dp[m-1];
            for(int i = m-2; i>=0; --i){
                right[i] = max(right[i+1] - 1, dp[i]);
            }
            
            for(int i = 0; i<m; ++i){
                dp[i] = max(left[i], right[i]) + points[j][i];
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};