class Solution {
    using ll = long long;
    ll calc(string target, string& s, int limit){
        int n = target.size(), m = s.size();
        if(n < m) return 0;
        if(n == m) return target >= s;

        ll ret = 0;
        int preLen = n - m;
        for(int i = 0; i<preLen; ++i){
            if(target[i] - '0' > limit){
                ret += (ll)pow(limit + 1, preLen - i);
                return ret;
            }else{
                ret += (ll)(target[i] - '0') * (ll)pow(limit + 1, preLen - i -1);
            }
        }

        string suffix = target.substr(preLen, m);
        return suffix >= s ? ret + 1:ret;
    }
public:
    ll numberOfPowerfulInt(ll start, ll finish, int limit, string s) {
        return calc(to_string(finish), s, limit) - calc(to_string(start - 1), s, limit);
    }
};