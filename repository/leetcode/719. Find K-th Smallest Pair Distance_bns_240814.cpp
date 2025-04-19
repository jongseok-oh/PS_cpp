class Solution {
    int count(int idx, int diff, vector<int>& nums){
        int n = nums.size();
        int target = nums[idx] + diff;
        int tarIdx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return tarIdx - idx - 1;
    }
    // diff 미만의 pair수의 합 O(nlogn)
    int countPairLowerThanDiff(int diff, vector<int>& nums){
        int ret = 0;
        for(int i = 0, n = nums.size(); i<n; ++i){
            int cnt = count(i, diff, nums);
            ret += cnt;
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