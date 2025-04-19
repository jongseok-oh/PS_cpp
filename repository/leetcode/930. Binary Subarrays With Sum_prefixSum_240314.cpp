class Solution {
    int cnt[30001];
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0, ret = 0;
        cnt[0] = 1;
        for(int num: nums){
            sum += num;
            if(sum >= goal) ret += cnt[sum - goal];
            ++cnt[sum];
        }
        return ret;
    }
};