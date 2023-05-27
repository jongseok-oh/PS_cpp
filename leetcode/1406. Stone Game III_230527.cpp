class Solution {

// idx 이후의 돌무더기에서
// 항상 최선으로 행동했을 때
// 얻을 수 있는 최대의 점수
int minMax(int idx, int n){
    if(idx >= n) return 0;

    int& ret = dp[idx];

    if(ret != 1e9) return ret;
    ret = -1e9;

    for(int d = 0; d<3; d++){
        int cnt = stoneCnt[d];
        int next = idx + cnt;

        if(next <= n){
            int score = suffixSum[idx] - suffixSum[next];
            ret = max(ret, score + suffixSum[next] - minMax(next, n));
        }
    }

    return ret;
}

int suffixSum[50001];
int dp[50000];
int stoneCnt[3] = {1,2,3};

public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();

        for(int i = n-1; i>=0; i--){
            suffixSum[i] = suffixSum[i+1] + stoneValue[i];
            dp[i] = 1e9;
        }

        int alice = minMax(0, n);
        int bob = suffixSum[0] - alice;

        if(alice == bob) return "Tie";

        return (alice > bob?"Alice":"Bob");
    }
};