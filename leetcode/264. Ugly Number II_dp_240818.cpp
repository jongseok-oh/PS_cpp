class Solution {
public:
    int nthUglyNumber(int n) {
        int i2 = 0, i3 = 0, i5 = 0;
        int val2, val3, val5;
        vector<int> ugly(n);
        ugly[0] = 1;
        for(int i = 1; i<n; ++i){
            val2 = ugly[i2] * 2, val3 = ugly[i3] * 3, val5 =  ugly[i5] * 5;
            int next = min({val2, val3, val5});
            ugly[i] = next;
            if(next == val2) ++i2;
            if(next == val3) ++i3;
            if(next == val5) ++i5;
        }
        return ugly[n-1];
    }
};