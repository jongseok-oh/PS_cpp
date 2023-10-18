class Solution {
    vector<int> con[50000];
    int indegree[50000];
    int dp[50000];
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        for(auto& rel: relations){
            con[rel[0]-1].push_back(rel[1]-1);
            ++indegree[rel[1]-1];
        }

        queue<int> q;
        int ret = 0;
        for(int i = 0; i<n; ++i)
            if(!indegree[i]) {
                dp[i] = time[i];
                q.push(i);
                ret = max(ret, dp[i]);
            }

        while(q.size()){
            int t = q.front(); q.pop();

            for(int& nNode : con[t]){
                dp[nNode] = max(dp[nNode], dp[t] + time[nNode]);
                ret = max(ret, dp[nNode]);
                if(!--indegree[nNode])
                    q.push(nNode);
            }
        }

        return ret;
    }
};