class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> cnt;

        for(int i = 0, n  = nums.size(); i<n-1; ++i){
            for(int j = i + 1; j<n; ++j){
                ++cnt[nums[i] * nums[j]];
            }
        }

        int ret = 0;
        for(auto& [k, v] : cnt){
            if(v >= 2) ret += v * (v-1) /2 * 8;
        }

        return ret;
    }
};