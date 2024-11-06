class Solution {
    int countBit(int num){
        int cnt = 0;
        for(int i = 0; i<=8; ++i){
            cnt += (bool)(num & (1<<i));
        }
        return cnt;
    }
public:
    bool canSortArray(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i<n; ){
            int bit = countBit(nums[i]);
            int j = i + 1;
            for(; j<n; ++j){
                if(bit != countBit(nums[j])) break;
            }
            sort(nums.begin() + i, nums.begin()+j);
            i = j;
        }
        for(int i = 0; i<n-1; ++i){
            if(nums[i] > nums[i+1]) return false;
        }
        return true;
    }
};