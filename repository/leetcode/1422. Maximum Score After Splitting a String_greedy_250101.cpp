class Solution {
public:
    int maxScore(string s) {
        int left = 0, right = 0;
        for(char c : s) right += (c == '1');

        int ret = 0;
        for(int i = 0; i<s.size()-1; ++i){
            char c = s[i];
            if(c == '0') ++left;
            else --right;
            ret = max(ret, left + right);
        }
        return ret;
    }
};