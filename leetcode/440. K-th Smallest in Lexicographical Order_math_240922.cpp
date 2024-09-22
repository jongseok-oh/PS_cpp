class Solution {
    using ll = long long;
    int getNumCnt(ll a, ll b, ll maxNum){
        int gap = 0;
        while(a <= maxNum){
            gap += min(maxNum + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return gap;
    }
public:
    int findKthNumber(int n, int k) {
        int prefix = 1;
        for(int order = 1; order<k;){
            int cnt = getNumCnt(prefix, prefix + 1, n);
            if(order + cnt <= k){
                order += cnt;
                ++prefix;
            }else {
                ++order;
                prefix *= 10;
            }
        }
        return prefix;
    }
};