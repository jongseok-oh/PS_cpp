class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int batch = 0, n = nums.size();
        for(int num : nums) {
            batch += (num == 1);
        }
        if(batch == 0 || batch == 1|| batch == nums.size() || batch == nums.size() -1) {
            return 0;
        }
        
        int i = 0, zeroCnt = 0;
        for(;i<batch -1; ++i){
            zeroCnt += (nums[i] == 0);
        }
        int ret = 1e9;
        for(; i<n*2; ++i){
            zeroCnt += (nums[i%n] == 0);
            ret = min(ret, zeroCnt);
            zeroCnt -= (nums[(i + n -(batch-1))%n] == 0);
        }
        return ret;
    }
};