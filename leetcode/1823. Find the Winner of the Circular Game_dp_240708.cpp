class Solution {
public:
    int findTheWinner(int n, int k) {
        int ret = 1;
        for(int i = 2; i<=n; ++i)
            ret = (ret + k - 1)%i + 1;
        return ret;
    }
};