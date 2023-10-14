class Solution {
    // dp[i][j] = 현재 i 인덱스이고
    // 현재까지 칠한 벽의 수가 j일 때
    // 최소 cost
    int dp[500][500];

    int n;
    int solve(int i, int j, vector<int>& cost, vector<int>& time){
        if(j >= n) return 0;
        if(i >= n) return 1e9;
        
        int& ret = dp[i][j];
        if(ret) return ret;

        return ret = min(
            solve(i + 1, j, cost, time),
            cost[i] + solve(i + 1, j + time[i] + 1, cost, time)
        );
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = time.size();
        return solve(0, 0, cost, time);
    }
};