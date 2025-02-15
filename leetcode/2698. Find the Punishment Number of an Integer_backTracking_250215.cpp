class Solution {
    bool isPunishment(int target, int sum, int num){
        if(num == 0) return target == sum;
        int div = 10;
        while(true){
            int tSum = sum + num % div;
            if(isPunishment(target, tSum, num / div)) {
                return true;
            }
            if(num / div == 0) break;
            div *= 10;
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        int ret = 0;
        for(int i = 1; i<=n; ++i){
            int square = i * i;
            if(isPunishment(i, 0, square)){
                ret += square;
            }
        }
        return ret;
    }
};