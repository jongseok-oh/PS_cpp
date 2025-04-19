class Solution {

    int suffixSum[101];
    int dp[100][100];

public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        
        for(int i = n-1; i>=0; i--) suffixSum[i] = suffixSum[i + 1] + piles[i];

        return minMax(1, 0, piles, n);
    }

    // 배열이 idx부터 시작하고
    // m 값이 m일 때 현재 플레이어가 최대의 돌을 얻는 개수를 반환
    int minMax(int m, int idx, vector<int>& piles, int n){
        
        // 남은 돌을 모두 가져갈 수 있는 경우
        if(idx + m * 2 >= n) return suffixSum[idx];

        int& ret = dp[idx][m];

        if(ret) return ret;

        // 남은 돌의 전체 수 suffixSum[idx]
        // 남은 돌 - 상대방의 idx+i 이후의 최대의 돌 수
        // i ~ 2 * m까지 골라보며 이 중 가장 큰 값을 반환
        for(int i = 1; i<= 2*m; i++)
            ret = max(ret, suffixSum[idx] - minMax(max(m, i), idx+i, piles, n));

        return ret;
    }
};