class Solution {
    void dfs(int node, int numCourses, vector<vector<bool>>& reachable, vector<vector<int>>& con){
        if(reachable[node][node]) return;
        reachable[node][node] = true;
        for(int next : con[node]){
            dfs(next, numCourses, reachable, con);

            for(int i = 0; i<numCourses; ++i){
                reachable[node][i] = reachable[node][i] | reachable[next][i];
            }
        }
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> con(numCourses);
        for(auto& pre: prerequisites){
            con[pre[0]].push_back(pre[1]);
        }
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses));

        for(int i = 0; i<numCourses; ++i){
            dfs(i, numCourses, reachable, con);
        }

        int m = queries.size();
        vector<bool> ret(m);
        for(int i = 0; i<m; ++i){
            const auto& q = queries[i];
            ret[i] = reachable[q[0]][q[1]];
        }

        return ret;
    }
};