class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](const auto& a, const auto& b){
            return (a % 2 == 0) && (b % 2 == 1);
        });

        return nums;
    }
};