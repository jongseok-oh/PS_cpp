class Solution {
    // 숫자가 i ~ j까지 있을 때
    // 최적으로 플레이해서 얻을 수 있는
    // 최대 점수
    int dp[20][20];
    int preSum[21];

    int solve(int left, int right, vector<int>& nums){
        if(left> right) return 0;
        int& ret = dp[left][right];

        if(ret != -1) return ret;

        int pre = preSum[right + 1] - preSum[left];

        // 누적합에서 상대의 최적의 플레이를 빼면
        // 나의 최적의 플레이가 나옴
        int getLeft = pre - solve(left + 1, right, nums);
        int getRight = pre - solve(left, right - 1, nums);

        return ret = max(getLeft, getRight);
    }
public:
    bool PredictTheWinner(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i<n; i++)
            preSum[i + 1] = preSum[i] + nums[i];
        
        memset(dp, -1, sizeof(dp));
        
        return preSum[n] <= solve(0, n - 1, nums) * 2;
    }
};