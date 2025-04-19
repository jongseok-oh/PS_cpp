class Solution {
    int hash(vector<int>& temp){
        long long _hash = 0;
        for(int num : temp){
            _hash *= 31;
            _hash += num;
            _hash %= 0x7fffffff;
        }
        return _hash;
    }
    void comb(int idx, int sum, int target, vector<int> temp, vector<int>& candidates, vector<vector<int>>& ret, unordered_set<int>& visit){
        if(sum == target){
            ret.emplace_back(temp);
            return;
        }
        if(idx >= candidates.size()) return;

        for(int i = idx; i<candidates.size(); ++i){
            int candi = candidates[i];
            if(sum + candi <= target){
                vector<int> t = temp;
                t.push_back(candi);
                int _hash = hash(t);
                if(visit.count(_hash)) continue;
                visit.insert(_hash);
                comb(i + 1, sum + candi,target, t, candidates, ret, visit);
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        unordered_set<int> visit;
        sort(candidates.begin(), candidates.end());
        comb(0, 0, target, {}, candidates, ret, visit);
        return ret;
    }
};