class Solution {
    typedef long long ll;
    const int MOD = 1e9 + 7;

    int getPCnt(string& c, int& i, int n){
        ++i;
        int ret = 0;
        while(i<n && c[i] == 'P') i++, ret++;
        return ret;
    }

public:
    int numberOfWays(string c) {
        int n = c.size();

        int totalSCnt = 0, sCnt = 0;
        ll ret = 1;
        for(int i = 0; i<n; ++i){
            if(c[i] == 'S') ++sCnt, ++totalSCnt;
            if(sCnt == 2){
                int pCnt = getPCnt(c, i, n);
                if(i < n) ret *= pCnt + 1, ret %= MOD, ++totalSCnt;
                sCnt = 1;
            }
        }

        return totalSCnt && !(totalSCnt&1)?ret:0;
    }
};