class Solution {
public:
    int maxScore(string s) {
        int left = 0,right = 0;
        for(char& c: s) right += c-'0';

        int ret = 0, n = s.size();
        for(int i = 0; i<n-1; ++i){
            if(s[i] == '0') ++left;
            else --right;

            int calc = left + right;
            if(ret < calc) ret = calc;
        }

        return ret;
    }
};