class Solution {
public:
    int numberOfMatches(int n) {
        int ret = 0;

        while(n != 1){
            ret += n/2;
            n = (n>>1) + (n&1);
        }

        return ret;
    }
};