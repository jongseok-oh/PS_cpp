class Solution {
    int factorial(int num){
        int ret = 1;
        for(int i = 1; i<=num; ++i) ret *= i;
        return ret;
    }
    void totalCnt(int idx, vector<int>& cnt, vector<int>& temp, int& ret){
        while(idx < 26 && cnt[idx] == 0) ++idx;
        if(idx == 26){
            int totalCnt = 0, div = 1;
            for(int i = 0; i<26; ++i){
                if(temp[i] > 0) {
                    totalCnt += temp[i];
                    div *= factorial(temp[i]);
                }
            }
            if(totalCnt == 0) return;
            ret += factorial(totalCnt)/div;
            return;
        }
        for(int tcnt = 0; tcnt<=cnt[idx]; ++tcnt){
            temp[idx] = tcnt;
            totalCnt(idx + 1, cnt, temp, ret);
        }
        temp[idx] = 0;
    }
public:
    int numTilePossibilities(string tiles) {
        vector<int> cnt(26), temp(26);
        for(char c : tiles) ++cnt[c-'A'];
        int ret = 0;
        totalCnt(0, cnt, temp, ret);
        return ret;
    }
};