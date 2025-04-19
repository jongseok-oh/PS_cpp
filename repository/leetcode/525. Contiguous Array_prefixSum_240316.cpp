class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> idx;

        idx[0] = -1;
        int oneCnt = 0, ret = 0;
        for(int i = 0; i<n; ++i){
            oneCnt += nums[i];
            int cal = 2*oneCnt - (i+1);
            if(idx.count(cal) != 0){
                ret = max(ret, i - idx[cal]);
            }else idx[cal] = i;
        }

        return ret;
    }
};