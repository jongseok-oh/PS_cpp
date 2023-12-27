class Solution {
public:
    int minCost(string colors, vector<int>& nt) {
        int n = nt.size(), ret = 0;
        
        int cnt = 1, preSum = nt[0], _max = nt[0];
        char prev = colors[0];

        for(int i = 1; i<=n; ++i){
            if(i == n || colors[i] != prev){
                if(cnt > 1){
                    ret += preSum - _max;
                }
                if(i != n){
                    cnt = 1; preSum = nt[i]; _max = nt[i];
                    prev = colors[i];
                }
            }else{
                ++cnt; preSum += nt[i]; _max = max(_max, nt[i]);
            }
        }

        return ret;
    }
};