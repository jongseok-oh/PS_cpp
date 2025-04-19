class Solution {
    int cCnt[26];
    int tCnt[26];
public:
    int countCharacters(vector<string>& words, string chars) {
        for(char& c: chars) ++cCnt[c-'a'];

        int ret = 0;
        for(auto& str: words){
            memset(tCnt, 0, 4 * 26);
            for(char& c: str) ++tCnt[c-'a'];

            bool good = true;
            
            for(int i = 0; i<26; ++i)
                if(cCnt[i] < tCnt[i]) {
                    good =false;
                    break;
                }
            if(good) ret += str.size();
        }

        return ret;
    }
};