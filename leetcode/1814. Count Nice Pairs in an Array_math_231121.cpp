class Solution {
    const int MOD = 1e9 + 7;

    int rev(int num){
        int ret = 0;

        while(num){
            ret *= 10;
            ret += num % 10;
            num /= 10;
        }

        return ret;
    }
public:
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> m;

        for(int& num: nums) ++m[num - rev(num)];

        int ret = 0;
        for(auto& p: m){
            ret += 1LL * p.second * (p.second - 1)/2 % MOD;
            ret %= MOD;
        }

        return ret;
    }
};