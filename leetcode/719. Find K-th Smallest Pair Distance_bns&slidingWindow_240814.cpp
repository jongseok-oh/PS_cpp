class Solution {
    // diff 미만의 pair수의 합 O(n)
    int countPairLowerThanDiff(int diff, vector<int>& nums){
        int ret = 0;
        for(int i = 0, j = 0, n = nums.size(); i<n; ++i){
            // diff 이상인 개수 탐색
            while(j<n && nums[j] - nums[i] < diff) ++j;
            ret += j - i -1;
        }
        return ret;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int low = 0, high = 1e6;
        while(low + 1 < high){
            int diff = (low + high)>>1;
            int cnt = countPairLowerThanDiff(diff, nums);
            if(cnt >= k) high = diff;
            else low = diff;
        }
        return low;
    }
};