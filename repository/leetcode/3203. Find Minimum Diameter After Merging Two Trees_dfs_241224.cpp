class Solution {
    int calcDiameter(vector<vector<int>>& edges){
        int n = edges.size() + 1;
        vector<vector<int>> con(n);
        for(auto& edge : edges){
            int a = edge[0], b = edge[1];
            con[a].push_back(b);
            con[b].push_back(a);
        }

        int ans = 0;
        function<int(int, int)> dfs = [&dfs, &ans, &con](int node, int parent){
            int m1 = -1, m2 = -1;
            for(int next : con[node]){
                if(next == parent) continue;
                int len = dfs(next, node);
                if(len > m1){
                    m2 = m1;
                    m1 = len;
                }else if(len > m2){
                    m2 = len;
                }
            }
            ans = max({ans, m1 + m2 + 2, m1 + 1});
            
            return m1 + 1;
        };

        dfs(0, -1);

        return ans;
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int diameter1 = calcDiameter(edges1);
        int diameter2 = calcDiameter(edges2);
        int mergeDiameter = 1 + (diameter1 + 1)/2 + (diameter2 + 1)/2;
        return max({diameter1, diameter2, mergeDiameter});
    }
};