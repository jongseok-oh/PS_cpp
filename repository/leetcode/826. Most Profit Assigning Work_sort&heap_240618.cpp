class Solution {
    struct DP{int d, p;};
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = worker.size();
        vector<DP> dps(n);
        for(int i = 0; i<n; ++i){
            dps[i].d = difficulty[i];
            dps[i].p = profit[i];
        }
        
        sort(worker.begin(), worker.end());
        sort(dps.begin(), dps.end(), [&](DP& a, DP& b){
            return a.d < b.d;
        });

        int idx = 0, ret = 0;
        priority_queue<int> q;
        for(int ability : worker){
            while(idx < n && dps[idx].d <=ability){
                q.push(dps[idx++].p);
            }
            if(q.size()) ret += q.top();
        }

        return ret;
    }
};