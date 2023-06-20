class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ret(n, -1);

        long long tsum = 0, left = 0;

        for(int i = 0; i<n; i++){
            tsum += nums[i];
            if(i - left == 2*k) ret[i-k] = tsum/(2*k + 1);
            if(i >= 2 * k) tsum -= nums[left++];
        }

        return ret;
    }
};