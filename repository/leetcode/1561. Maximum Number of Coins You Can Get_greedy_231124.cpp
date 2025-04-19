class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), [](auto& a, auto& b){
            return a > b;
        });

        int n = piles.size();

        int ret = 0;
        for(int i = 1, j = 0; j<n/3; i +=2, j++)
            ret+= piles[i];
        
        return ret;
    }
};