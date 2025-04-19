#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[300001][2];
vector<int> con[300001];

int solve(int node, int contain, vector<int>& sales){
    if(!con[node].size()) return (contain?sales[node-1]:0);
    
    if(contain == -1) return min(solve(node, 0, sales), solve(node, 1, sales));
    
    int& ret = dp[node][contain];
    if(ret != -1) return ret;
    
    ret = sales[node -1];
    if(contain){
        for(int child : con[node])
            ret += min(solve(child, 0, sales), solve(child, 1, sales));
    }else{
        bool isChildContain = false;
        int sum = 0;
        for(int child : con[node]){
            int cCon = solve(child, 1, sales), cNoCon = solve(child, 0, sales);
            sum += min(cCon, cNoCon);
            if(cNoCon >= cCon) isChildContain = true;
        }
        if(isChildContain) ret = sum;
        else{
            int minDiff = 0x7fffffff;
            for(int child : con[node]){
                int diff = solve(child, 1, sales) - solve(child, 0, sales);
                if(diff < minDiff) minDiff = diff;
            }
            ret = sum + minDiff;
        }
    }
    return ret;
}

int solution(vector<int> sales, vector<vector<int>> links) {
    for(auto& ab:links) con[ab[0]].push_back(ab[1]);
    memset(dp, -1, sizeof dp);
    return solve(1, -1, sales);
}