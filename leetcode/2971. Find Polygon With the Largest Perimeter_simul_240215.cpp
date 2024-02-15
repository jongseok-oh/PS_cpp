class Solution {
    typedef long long ll;
public:
    ll largestPerimeter(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());
        ll sum = nums[0] + nums[1], ret = -1;

        for(int i = 2; i<n; ++i){
            if(sum > nums[i] && ret < sum + nums[i])
                ret = sum + nums[i];
            sum += nums[i];
        }
        return ret;
    }
};