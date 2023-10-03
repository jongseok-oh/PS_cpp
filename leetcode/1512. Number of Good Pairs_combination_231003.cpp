class Solution {
    int cnt[101];
public:
    int numIdenticalPairs(vector<int>& nums) {
        for(int& num: nums) cnt[num]++;

        int ret = 0;

        for(int i = 1; i<=100; ++i) ret += cnt[i] * (cnt[i] - 1) /2;

        return ret;
    }
};