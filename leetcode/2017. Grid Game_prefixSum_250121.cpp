class Solution {
    using ll = long long;
public:
    ll gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        vector<ll> prefixSumUp(n + 1),prefixSumDown(n + 1);
        for(int i = 0; i<n; ++i) {
            prefixSumUp[i+1] = prefixSumUp[i] + grid[0][i];
            prefixSumDown[i+1] = prefixSumDown[i] + grid[1][i];
        }

        ll ret = prefixSumUp[n] - prefixSumUp[1];
        for(int i = 1; i<n; ++i){
            ll upSum = prefixSumUp[n] - prefixSumUp[i+1];
            ll downSum = prefixSumDown[i] - prefixSumDown[0];

            ret = min(ret, max(upSum, downSum));
        }

        return ret;
    }
};