class Solution {
    bool backTracking(int idx, int visit, string& pattern, string& ret){
        int n = ret.size();
        if(idx == n) return true;
        int oper = (pattern[idx - 1] == 'I'?1:-1);
        for(int num = ret[idx -1] - '0' + oper; num>0 && num<10; num += oper){
            if(visit & (1<<num)) continue;
            ret[idx] = num + '0';
            if(backTracking(idx + 1, visit | (1<<num), pattern, ret)){
                return true;
            }
        }
        return false;
    }
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string ret(n+1, ' ');
        for(int i = 1; i<=9; ++i){
            ret[0] = '0' + i;
            if(backTracking(1, 1<<i, pattern, ret)) break;
        }
        return ret;
    }
};