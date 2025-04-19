class Solution {
public:
    int pivotInteger(int n) {
        int A = (n + 1)*n/2;
        double ret = sqrt(A);
        if(ret - ((int)ret) >= 1e-6) return -1;
        return ret;
    }
};