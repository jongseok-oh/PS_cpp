class Solution {
public:
    int findComplement(int num) {
        int ret = 0, bit = 0;
        while(num){
            ret += ((num&1)^1)<<bit++;
            num >>=1;
        }
        return ret;
    }
};