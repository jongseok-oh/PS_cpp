class Solution {
    int idx[26];
public:
    int maxLengthBetweenEqualCharacters(string s) {
        memset(idx, -1, sizeof idx);
        int ret = -1;
        for(int i = 0; i<s.size(); ++i){
            int& tIdx = idx[s[i]-'a'];
            if(tIdx == -1) tIdx = i;
            else ret = max(ret, i - tIdx -1);
        }

        return ret;
    }
};