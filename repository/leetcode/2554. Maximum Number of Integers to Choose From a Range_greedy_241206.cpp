class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        bitset<10001> ban;
        for(int b : banned) ban[b] = 1;

        int ret = 0;
        for(int i = 1; i<=n && maxSum >= i; ++i){
            if(ban[i]) continue;
            ++ret;
            maxSum -= i;
        }
        return ret;
    }
};