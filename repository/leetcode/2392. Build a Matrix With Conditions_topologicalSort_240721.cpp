class Solution {
    vector<int> makeOrder(int k, vector<vector<int>>& condition){
        vector<int> con[k+1];
        vector<int> indeg(k + 1);

        for(auto& cond : condition){
            int f = cond[0], t = cond[1];
            ++indeg[t];
            con[f].push_back(t);
        }
        
        queue<int> q;
        for(int i = 1; i<=k; ++i){
            if(indeg[i] == 0) q.push(i);
        }

        vector<int> order;
        while(q.size()){
            int t = q.front(); q.pop();
            order.push_back(t);
            for(int next : con[t]){
                if(--indeg[next] == 0){
                    q.push(next);
                }
            }
        }
        return order;
    }
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rOrder = makeOrder(k, rowConditions);
        if(rOrder.size() != k) return {};
        vector<int> cOrder = makeOrder(k, colConditions);
        if(cOrder.size() != k) return {};
        
        unordered_map<int, int> revr, revc;
        for(int i = 0; i<k; ++i){
            revr[rOrder[i]] = i;
            revc[cOrder[i]] = i;
        }

        vector<vector<int>> ret(k, vector<int>(k));
        for(int i = 1; i<=k; ++i) ret[revr[i]][revc[i]] = i;
        return ret;
    }
};