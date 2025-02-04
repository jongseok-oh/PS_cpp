class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int sum = nums[0], ret = sum;
        for(int i = 1, n = nums.size(); i<n; ++i){
            int num = nums[i];
            if(num > nums[i-1]) sum += num;
            else sum = num;
            ret = max(ret, sum);
        }
        
        return ret;
    }
};