class Solution {
    double plus(double x, int n){
        double ret = 1;

        while(n){
            if(n&1) ret *= x;
            x *= x;
            n >>= 1;
        }

        return ret;
    }

    double minus(double x, long long n){
        double ret = 1;
        n *= -1;

        while(n){
            if(n&1) ret /= x;
            x *= x;
            n >>= 1;
        }

        return ret;
    }
public:
    double myPow(double x, int n) {
        if(!n) return 1;

        if(n < 0) return minus(x,n);
        else return plus(x,n);
    }
};