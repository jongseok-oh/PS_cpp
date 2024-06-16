class Solution {
    typedef long long ll;
public:
    int minPatches(vector<int>& nums, int n) {
        ll sum = 0, ret = 0;
        for(int num : nums){
            while(sum < n && sum + 1 < num){
                sum += sum + 1;
                ++ret;
            }
            sum += num;
            if(sum >= n) return ret;
        }
        while(sum < n){
            sum += sum + 1;
            ++ret;
        }
        return ret;
    }
};