class Solution {
public:
    int reverse(int x) {
        long long ret = 0;
        while(x){
            ret *= 10;
            if(ret > INT_MAX || ret < INT_MIN) return 0;
            ret += x % 10;
            x/=10;
        }
        return ret;
    }
};