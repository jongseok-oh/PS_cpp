class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = 1e9, n = nums.size();

        int left = 0 , right = 0;
        int sum = 0;
        while(left <= right){
            if(sum < target){
                if(right == n) break;
                sum += nums[right++];
            }
            else{
                sum -= nums[left++];
                ans = min(ans, right - left + 1);
            }
        }

        return (ans ==1e9?0:ans);
    }
};