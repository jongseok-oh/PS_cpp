class Solution {
    bool isMatch(char s, char p){
        if(p == '.') return true;
        return s == p;
    }
    bool isTotalMatch(int sIdx, int pIdx, string& s, string& p){
        if(pIdx < p.size() -1 && p[pIdx + 1] == '*'){
            if(isTotalMatch(sIdx, pIdx + 2, s, p)){
                return true;
            }
            int tsIdx = sIdx;
            while(tsIdx <s.size() && isMatch(s[tsIdx],p[pIdx])){
                if(isTotalMatch(tsIdx + 1, pIdx + 2, s, p)){
                    return true;
                }
                ++tsIdx;
            }
        }
        if(sIdx == s.size()) return pIdx == p.size();

        if(isMatch(s[sIdx], p[pIdx]) && isTotalMatch(sIdx + 1, pIdx + 1, s, p)){
            return true;
        }
        return false;
    }
public:
    bool isMatch(string s, string p) {
        return isTotalMatch(0,0,s,p);
    }
};