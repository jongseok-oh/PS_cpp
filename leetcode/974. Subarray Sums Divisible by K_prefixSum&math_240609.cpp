class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int prefixSum = 0, ret = 0;
        for(int num : nums){
            prefixSum = ((prefixSum + num) % k + k) % k;
            if(cnt.count(prefixSum)) ret += cnt[prefixSum];
            ++cnt[prefixSum];
        }
        return ret;
    }
};