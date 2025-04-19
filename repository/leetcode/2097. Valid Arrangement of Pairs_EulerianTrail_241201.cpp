class Solution {
    void dfs(int node, vector<int>& order, unordered_map<int, vector<int>>& con){
        while(con[node].size()){
            int next = con[node].back();
            con[node].pop_back();
            dfs(next, order, con);
        }
        order.push_back(node);
    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, vector<int>> con;
        unordered_map<int, int> indeg, outdeg;
        for(auto& pair : pairs){
            int a = pair[0], b= pair[1];
            con[a].push_back(b);
            ++indeg[b];
            ++outdeg[a];
        }

        int start = pairs[0][0];
        for(auto& [node, outCnt] : outdeg){
            int inCnt = indeg[node];
            if(inCnt + 1 == outCnt) {
                start = node;
                break;
            }
        }

        vector<int> reverseOrder;
        dfs(start, reverseOrder, con);

        int n = reverseOrder.size();
        vector<vector<int>> ret(n-1);
        for(int i = n-1; i>0; --i){
            ret[(n-1)-i] = {reverseOrder[i], reverseOrder[i-1]};
        }
        return ret;
    }
};