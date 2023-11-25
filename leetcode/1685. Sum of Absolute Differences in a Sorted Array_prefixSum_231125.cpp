class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);

        int sum = 0, preSum = 0;
        for(int& num: nums) sum += num;

        for(int i = 0; i<n; ++i){
            int left = i * nums[i] - preSum;
            int right = sum - preSum - (n - i) * nums[i];
            ret[i] = left + right;
            preSum += nums[i];
        }

        return ret;
    }
};