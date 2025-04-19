class Solution {
public:
    int totalMoney(int n) {
        int ret = 0, monDay = 1;

        for(int i = 0; i<n/7; ++i)
            ret += (monDay++ + 3) * 7;
        
        int mod = n % 7;
        ret += (monDay * 2 + mod - 1)* mod/2;

        return ret;
    }
};