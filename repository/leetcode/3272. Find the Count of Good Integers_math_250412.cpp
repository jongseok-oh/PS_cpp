class Solution {
    using ll = long long;
public:
    ll countGoodIntegers(int n, int k) {
        unordered_set<string> set;
        int start = pow(10, (n-1)/2);
        for(int i = start; i<start*10; ++i){
            string s = to_string(i);
            s += string(s.rbegin() + (n&1), s.rend());
            ll num = stol(s);
            if(num % k == 0){
                sort(s.begin(), s.end());
                set.emplace(s);
            }
        }

        vector<ll> factorial(n+1, 1);
        for(int i = 2; i<=n; ++i){
            factorial[i] = factorial[i-1] * i;
        }

        ll ret = 0;
        for(const string& s : set){
            vector<int> cnt(10);
            for(char c : s) ++cnt[c-'0'];

            ll temp = ((ll)n - cnt[0]) * factorial[n-1];
            for(int num : cnt) temp /= factorial[num];
            ret += temp;
        }

        return ret;
    }
};