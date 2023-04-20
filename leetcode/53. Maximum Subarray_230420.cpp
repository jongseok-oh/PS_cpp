class Solution {
public:
    int maxSubArray(vector<int>& nums) { 
        int n = nums.size();

        int ans = -1e9;
        int t = 0;

        for(int i = n-1; i>=0; i--){
            t = (t>0?t:0) + nums[i];
            ans = max(ans, t);
        }
        return ans;
    }
};