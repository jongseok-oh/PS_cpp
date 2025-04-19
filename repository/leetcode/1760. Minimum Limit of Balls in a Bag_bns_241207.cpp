class Solution {
    bool check(vector<int>& nums, int target, int maxOperations){
        int operations = 0;
        for(int num : nums){
            if(num >= target){
                operations += (num + target - 1) / target - 1;
            }
        }
        return operations > maxOperations;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 0, high = 1e9;
        while(low + 1 < high){
            int mid = (low + high)>>1;
            if(check(nums, mid, maxOperations)){
                low = mid;
            }else high = mid;
        }
        return high;
    }
};