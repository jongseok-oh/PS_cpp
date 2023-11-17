class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int _max = -1, n = nums.size();
        for(int i = 0; i<n/2; ++i){
            int calc = nums[i] + nums[n-i-1];
            if(calc > _max) _max = calc;
        }

        return _max;
    }
};