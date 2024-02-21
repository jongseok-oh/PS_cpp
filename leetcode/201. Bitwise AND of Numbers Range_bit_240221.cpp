class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ret = 0;
        for(int i = 31; i>=0; --i){
            if((left & (1<<i)) ^ (right & (1<<i))) break;
            else ret |= (left & (1<<i));
        }
        return ret;
    }
};