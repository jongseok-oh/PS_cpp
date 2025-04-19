class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(3);
        for(int num : nums) ++cnt[num];
        for(int i = 0, j=0; i<n; ++j){
            while(i<n && cnt[j]--)nums[i++] = j;
        }
    }
};