class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int noDistinct = 0;
        vector<int> cnt(101);
        for(int num : nums) {
            if(++cnt[num] == 2) ++noDistinct;
        }
        if(noDistinct == 0) return 0;
        
        int operation = 0;
        for(int i = 0, n = nums.size(); i<n; i+=3){
            for(int j = 0; i + j < n && j<3; ++j){
                if(--cnt[nums[i + j]] == 1) --noDistinct;
            }
            ++operation;
            if(noDistinct == 0) break;
        }

        return operation;
    }
};