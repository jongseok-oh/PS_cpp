class Solution {
    using ll = long long;
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<ll> exist, visit;
        for(int num : nums) exist.insert(num);

        int ret = -1;
        sort(nums.begin(), nums.end());
        for(int num : nums){
            int length = 0;
            if(visit.count(num)) continue;
            ll temp = num;
            while(exist.count(temp)){
                ++length;
                visit.insert(temp);
                temp *= temp;
            }
            if(length >= 2) ret = max(ret, length);
        }
        return ret;
    }
};