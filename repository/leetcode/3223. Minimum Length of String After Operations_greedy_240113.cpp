class Solution {
public:
    int minimumLength(string s) {
        vector<int> cnt(26);
        for(char c : s) ++cnt[c-'a'];

        int ret = 0;
        for(int i = 0; i<26; ++i){
            int len = cnt[i];
            if(len&1) ++ret;
            else if(len > 0) ret += 2;
        }
        return ret;
    }
};