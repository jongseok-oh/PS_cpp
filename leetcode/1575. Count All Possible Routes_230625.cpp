class Solution {
    const int MOD = 1e9 +7;
    // dp[i][j] 현재 i 위치에
    // 기름이 j 남았을 때
    // 갈 수 있는 경우의 수
    int dp[100][201];
    
    int end;
    int solve(int t, int fuel, vector<int>& locations){
        int& ret = dp[t][fuel];
        if(ret != -1) return ret;
        ret = (t == end?1:0);

        for(int i = 0; i<locations.size(); i++){
            int cost = abs(locations[i] - locations[t]);
            if(t != i && fuel >= cost) {
                ret += solve(i, fuel - cost, locations);
                ret %= MOD;
            }
        }

        return ret;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp, -1, sizeof(dp));
        end = finish;
        return solve(start, fuel, locations);
    }
};