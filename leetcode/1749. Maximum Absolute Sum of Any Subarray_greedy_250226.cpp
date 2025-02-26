class Solution {
    int maxPositive(vector<int>& nums){
        int prevSum = 0, ret = 0;
        for(int num : nums){
            int sum = (prevSum <0?0:prevSum) + num;
            ret = max(ret, sum);
            prevSum = sum;
        }
        return ret;
    }
    int maxNegative(vector<int>& nums){
        int prevSum = 0, ret = 0;
        for(int num : nums){
            int sum = (prevSum >0?0:prevSum) + num;
            ret = min(ret, sum);
            prevSum = sum;
        }
        return ret;
    }
public:
    int maxAbsoluteSum(vector<int>& nums) {
        return max(maxPositive(nums), -maxNegative(nums));
    }
};