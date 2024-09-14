class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxNum = *max_element(nums.begin(), nums.end());

        int maxLen = -1, prev = -1, tempLen = -1;
        for(int num : nums){
            if(num == maxNum){
                if(prev == maxNum){
                    tempLen++;
                }else{
                    tempLen = 1;
                }
                maxLen = max(maxLen, tempLen);
            }
            prev = num;
        }

        return maxLen;
    }
};