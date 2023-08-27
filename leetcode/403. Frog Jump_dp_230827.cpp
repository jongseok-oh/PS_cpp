class Solution {
    unordered_set<int> dp[2000];

    bool solve(int idx, int k,vector<int>& stones){
        if(idx == stones.size() - 1) return true;

        if(dp[idx].find(k) != dp[idx].end()) return false;

        dp[idx].insert(k);

        int tLoc = stones[idx];
        for(int j : {k -1, k, k+1}){
            if(j <= 0) continue;
            for(int i = idx + 1; i<stones.size(); i++){
                if(tLoc + j < stones[i]) break;
                if(tLoc + j == stones[i]){
                    if(solve(i, j, stones)) return true;
                    break;
                }
            }
        }

        return false;
    }
public:
    bool canCross(vector<int>& stones) {
        return solve(0, 0, stones);
    }
};