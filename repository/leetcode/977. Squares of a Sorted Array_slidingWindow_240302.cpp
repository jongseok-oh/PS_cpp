class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ret(n);

        int l = 0, r = n-1;
        for(int i = n-1; i>=0; --i){
            int L = nums[l]*nums[l], R = nums[r]*nums[r];
            if(L>=R){
                ret[i] = L; ++l;
            }else{
                ret[i] = R; --r;
            }
        }

        return ret;
    }
};