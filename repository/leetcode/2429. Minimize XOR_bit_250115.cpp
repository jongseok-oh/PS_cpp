class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bitCnt = 0;
        while(num2){
            bitCnt += num2&1;
            num2 >>= 1;
        }

        int ret = 0;
        for(int i = 31; i>=0 && bitCnt>0; --i){
            if(num1 & (1<<i)){
                ret |= (1<<i);
                --bitCnt;
            }
        }

        for(int i = 0; i<32 && bitCnt>0; ++i){
            if(!(ret & (1<<i))){
                ret |= (1<<i);
                --bitCnt;
            }
        }
        return ret;
    }
};