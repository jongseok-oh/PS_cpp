#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool visit[100001];
int dp[100001][2];
vector<int> con[100001];

void solve(int t){
    visit[t] = true;
    dp[t][1] = 1;
    for(int i =0, len = con[t].size(); i<len; i++){
        int nnode = con[t][i];
        if(visit[nnode]) continue;
        solve(nnode);
        
        dp[t][1] += min(dp[nnode][0], dp[nnode][1]);
        dp[t][0] += dp[nnode][1];
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    for(vector<int>& lh:lighthouse)
    {
        con[lh[0]].push_back(lh[1]);
        con[lh[1]].push_back(lh[0]);
    }
    solve(1);
    
    return min(dp[1][0],dp[1][1]);
}