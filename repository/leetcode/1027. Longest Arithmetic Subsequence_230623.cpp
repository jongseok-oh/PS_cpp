class Solution {

    // dp[i][j] = i에서 시작해서
    // 차이가 500 + j인
    // longest arithmetic subsequence
    int dp[1000][1001];
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();

        for(int j = 0; j<n; j++) for(int i  = 0; i<=1000; i++)
            dp[j][i] = 1;

        int ans = 1;
        for(int i = n-2; i>=0; i--){
            for(int j = i +1; j<n; j++){
                int diff = nums[i] - nums[j] + 500;

                dp[i][diff]  = max(dp[i][diff] , dp[j][diff] + 1);
                ans = max(ans, dp[i][diff]);
            }
        }
        
        return ans;
    }
};