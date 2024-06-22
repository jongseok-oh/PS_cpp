class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prevEvenCnt;

        int cnt = 0;
        for(int i = 0; i<n; ++i){
            if(nums[i]&1){
                prevEvenCnt.push_back(cnt);
                cnt=0;
            }else ++cnt;
        }
        prevEvenCnt.push_back(cnt);
        
        int ret = 0;
        int oddCnt = 0, m = prevEvenCnt.size();
        for(int i = 0, j = 0; i<m-1 && j<m-1; ++i){
            while(j<m-1 && oddCnt<k) oddCnt++, ++j;
            if(oddCnt == k){
                ret += (prevEvenCnt[i] + 1) * (prevEvenCnt[j] + 1);
            }
            --oddCnt;
        }
        
        return ret;
    }
};