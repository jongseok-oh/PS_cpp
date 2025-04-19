class Solution {

public:
    int minFlips(int a, int b, int c) {
        
        int ret = 0;

        while(a > 0 || b >0 || c > 0){
            int aBit = a & 1;
            int bBit = b & 1;
            int cBit = c & 1;

            if(cBit){
                if(!aBit && !bBit) ret++;
            }else ret += aBit + bBit;

            a >>= 1;
            b >>= 1;
            c >>= 1;
        }

        return ret;
    }
};