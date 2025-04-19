class Solution {
    typedef long long ll;
    int MOD = 1e9 + 7;
    int cnt[26];
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<ll, vector<string>> m;

        for(string& str: strs){
            memset(cnt, 0, sizeof cnt);
            for(char c: str) cnt[c -'a']++;
            ll key = 0;

            for(int i = 0; i<26; ++i){
                key *= 31;
                key %= MOD;
                key += cnt[i];
            }

            m[key].push_back(str);
        }

        vector<vector<string>> ret;

        for(auto& kv: m) ret.push_back(kv.second);
        return ret;
    }
};