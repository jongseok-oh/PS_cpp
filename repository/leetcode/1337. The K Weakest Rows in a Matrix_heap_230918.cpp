class Solution {
    struct Weak{
        int cnt, idx;

        bool operator < (const auto& a) const{
            if(this->cnt == a.cnt) return this->idx > a.idx;
            return this->cnt > a.cnt;
        }
    };
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<Weak> q;

        for(int i = 0; i< mat.size(); ++i){
            int cnt = 0;
            for(int& t: mat[i]) cnt += t;

            q.push({cnt, i});
        }

        vector<int> ret;
        while(k--){
            ret.push_back(q.top().idx);
            q.pop();
        }

        return ret;
    }
};