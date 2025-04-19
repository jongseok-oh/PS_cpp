class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        for(int i = 1, n = nums.size(); i <(1<<n); ++i){
            int temp = 0;
            for(int j = 0; j<n; ++j){
                if((1<<j)&i) temp ^= nums[j];
            }
            sum += temp;
        }
        return sum;
    }
};