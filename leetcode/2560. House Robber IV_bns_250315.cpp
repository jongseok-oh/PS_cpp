class Solution {
    int collectHouses(int pivot, vector<int>& nums){
        int cnt = 0;
        for(int i = 0, n = nums.size(); i<n;){
            while(i<n && nums[i]>pivot) ++i;
            if(i <n){
                ++cnt;
                i += 2;
            }
        }
        return cnt;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int low = 0, high = 1e9;
        while(low + 1 < high){
            int mid = (low + high)>>1;
            if(collectHouses(mid, nums) >= k){
                high = mid;
            }else low = mid;
        }
        return high;
    }
};