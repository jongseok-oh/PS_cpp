class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dominant = -1, n = nums.size();
        unordered_map<int,int> cnt;
        for(int num : nums) {
            if(++cnt[num]>=n/2) dominant = num;
        }

        int dominantCnt = 0, totalDominantCnt = cnt[dominant];
        for(int i = 0; i<n; ++i){
            if(nums[i] == dominant) ++dominantCnt;
            if(dominantCnt > (i+1)/2 && (totalDominantCnt - dominantCnt) > (n-i-1)/2){
                return i;
            }
        }
        return -1;
    }
};