static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return nums[0];

        int tMin = nums[k], i = k, j = k, ans = -0x7fffffff;

        while(i > 0 || j < n - 1){
            if(i == 0) ++j;
            else if(j == n-1) --i;
            else {
                if(nums[i - 1] > nums[j + 1]) --i;
                else ++j;
            }
            tMin = min({tMin, nums[i], nums[j]});
            ans = max(ans, tMin * (j - i + 1));
        }

        return ans;
    }
};