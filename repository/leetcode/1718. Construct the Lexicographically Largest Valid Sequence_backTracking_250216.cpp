class Solution {
    bool backTracking(int idx, int visit, int n, vector<int>& ret){
        while(idx < ret.size() && ret[idx] != 0) ++idx;
        if(idx == ret.size()) return true;

        for(int num = n; num>=1; --num){
            if((1<<num)&visit) continue;

            int pairIdx = num == 1?idx:idx+num;
            if(pairIdx >= ret.size() || ret[pairIdx] != 0) continue;
            
            ret[idx] = num;
            ret[pairIdx] = num;
            if(backTracking(idx+1, visit | (1<<num), n, ret)) return true;
            ret[idx] = 0;
            ret[pairIdx] = 0;
        }

        return false;
    }
public:
    vector<int> constructDistancedSequence(int n) {
        vector<int> ret(2*n-1);
        backTracking(0, 0, n, ret);
        return ret;
    }
};