class Solution {
    int dp[100][100];

    int solve(int rIdx, int kIdx,const string& ring,const string& key){
        if(kIdx == key.size()) return 0;
        int& ret = dp[rIdx][kIdx];
        if(ret != -1) return ret;
        ret = 1e9;
        int n = ring.size();
        int leftCnt = n&1?n/2+1:n/2;
        int rightCnt = n/2+1;

        for(int cnt = 0; cnt<leftCnt; ++cnt){
            int leftRIdx = (rIdx - cnt + n) % n;
            if(ring[leftRIdx] == key[kIdx])
                ret = min(ret, 1 + cnt + solve(leftRIdx, kIdx + 1, ring, key));
        }

        for(int cnt = 1; cnt<rightCnt; ++cnt){
            int rightRIdx = (rIdx + cnt) % n;
            if(ring[rightRIdx] == key[kIdx])
                ret = min(ret, 1 + cnt + solve(rightRIdx, kIdx + 1, ring, key));
        }

        return ret;
    }
public:
    int findRotateSteps(string ring, string key) {
        memset(dp, -1 ,sizeof dp);
        return solve(0,0,ring, key);
    }
};