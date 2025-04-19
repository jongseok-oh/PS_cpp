class Solution {
    struct Q{
        int q, idx;
    };
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [](auto& a, auto& b){
            return a[0] < b[0];
        });
        
        int n = queries.size();
        vector<Q> qs(n);
        for(int i = 0; i<n; ++i){
            auto& q = qs[i];
            q.q = queries[i];
            q.idx = i;
        }

        sort(qs.begin(), qs.end(), [](auto& q1, auto& q2){
            return q1.q < q2.q;
        });

        int _max = 0;
        vector<int> ret(n);
        for(int i = 0, j = 0, m = items.size(); i<n; ++i){
            int q = qs[i].q;
            while(j<m && items[j][0] <= q){
                _max = max(_max, items[j++][1]);
            }
            ret[qs[i].idx] = _max;
        }

        return ret;
    }
};