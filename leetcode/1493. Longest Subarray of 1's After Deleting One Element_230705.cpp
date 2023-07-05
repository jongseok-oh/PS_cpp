class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        int before1 = 0, before2 = 0;
        for(int i = n-1; i>=0; i--){
            if(nums[i] == 1){
                before1++; before2++;
            }else{
                before2 = before1; before1 = 0;
            }
            ans = max({ans, before1, before2});
        }
        return (ans==n?ans-1:ans);
    }
};