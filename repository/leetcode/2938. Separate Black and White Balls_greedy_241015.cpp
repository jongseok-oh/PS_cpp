class Solution {
    using ll = long long;
public:
    ll minimumSteps(string s) {
        ll ret = 0;
        for(int i = 0, correctIdx = 0, n = s.size(); i<n; ++i){
            if(s[i] == '0'){
                ret += i - correctIdx++;
            }
        }
        return ret;
    }
};