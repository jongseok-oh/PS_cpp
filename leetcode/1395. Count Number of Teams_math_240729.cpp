class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size(), ret = 0;
        for(int i = 0; i<n; ++i){
            int me = rating[i];
            int bigL = 0, smallL = 0;
            int bigR = 0, smallR = 0;
            int j = i-1;
            while(j>=0){
                if(rating[j] > me) ++bigL;
                else ++smallL;
                --j;
            }
            j = i + 1;
            while(j<n){
                if(rating[j] > me) ++bigR;
                else ++smallR;
                ++j;
            }
            ret += smallL * bigR + bigL * smallR;
        }
        return ret;
    }
};