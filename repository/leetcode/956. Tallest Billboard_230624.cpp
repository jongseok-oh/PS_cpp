class Solution {

// dp[i] = 두 빌보드의 차이가 i일 때
// 빌보드 최대 높이
int dp[5001];
int tempDp[5001];

void copy(int sum){
    for(int i = 0; i<=sum; i++) tempDp[i] = dp[i];
}

public:
    int tallestBillboard(vector<int>& rods) {
        int sum  = 0;
        for(int rod: rods) sum += rod;

        memset(dp, -1, (sum + 1) * 4);

        dp[0] = 0;
        for(int rod: rods){
            copy(sum);

            for(int i = 0; i<=sum - rod; i++){
                if(tempDp[i] < 0) continue;

                // 더 큰 빌보드에 rod를 올린다.
                dp[i + rod] = max(dp[i + rod], tempDp[i] + rod);

                // 작은 빌보드에 rod를 올린다.
                int diff = abs(rod - i);
                int smallOne = tempDp[i] - i, bigOne = tempDp[i];
                dp[diff] = max(dp[diff], max(smallOne + rod, bigOne));
            }
        }
        
        return dp[0];
    }
};