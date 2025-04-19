class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorEq = 0;
        for(int num : nums) xorEq ^= num;

        int cnt = 0;
        while(xorEq != k){
            cnt += (xorEq^k)&1;
            xorEq >>=1;
            k >>=1;
        }
        return cnt;
    }
};