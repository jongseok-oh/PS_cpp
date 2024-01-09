class Solution {
    int table[2500];
public:
    int lengthOfLIS(vector<int>& nums) {
        int length = 1, n = nums.size();

        table[0] = nums[0];

        for(int i = 1;i<n; ++i){
            if(table[length - 1] < nums[i]){
                table[length++] = nums[i];
            }else{
                int low = -1, high = length;

                while(low + 1 < high){
                    int mid = (low + high)>>1;
                    if(table[mid] >= nums[i]) high = mid;
                    else low = mid;
                }

                table[high] = nums[i];
            }
        }

        return length;
    }
};