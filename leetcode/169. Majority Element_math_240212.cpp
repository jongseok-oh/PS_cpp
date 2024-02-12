class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, ret = 0;

        for(int num : nums){
            if(ret == num) ++cnt;
            else{
                if(--cnt < 0){
                    cnt = 1; ret = num;
                }
            }
        }

        return ret;
    }
};