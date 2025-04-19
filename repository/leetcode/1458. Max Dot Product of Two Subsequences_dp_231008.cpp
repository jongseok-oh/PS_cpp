class Solution {
    // dp[i][j]
    // num1[i], num2[j]에서 시작했을 때
    // 내적의 최대 값
    int dp[500][500];

    int n,m;
    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2){
        int& ret = dp[i][j];
        if(ret != -1e9) return ret;

        ret = nums1[i] * nums2[j];

        int temp = 0;
        if(i < n -1 && j < m -1){
            temp = solve(i + 1, j + 1, nums1, nums2);
            ret = max({ret, ret + temp, temp});
        }

        if(i < n -1)
            ret = max(ret, solve(i + 1, j, nums1, nums2));

        if(j < m - 1)
            ret = max(ret, solve(i, j + 1, nums1, nums2));

        return ret;
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        n = nums1.size(); m = nums2.size();

        // -1000 * 1000 * 500 = -5*1e8
        for(int i =0; i<n; ++i) for(int j = 0; j<m; ++j)
            dp[i][j] = -1e9;
        
        return solve(0,0,nums1, nums2);
    }
};