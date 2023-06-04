class Solution {

    void dfs(int t, vector<bool>& visit, vector<vector<int>>& isConnected){
        visit[t] = true;

        for(int i = 0; i<isConnected.size(); i++)
            if(isConnected[t][i] && !visit[i])
                dfs(i, visit, isConnected);
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visit(n);

        int cnt = 0;
        for(int i = 0; i<n; i++){
            if(visit[i]) continue;

            cnt++;

            dfs(i, visit, isConnected);
        }

        return cnt;
    }
};