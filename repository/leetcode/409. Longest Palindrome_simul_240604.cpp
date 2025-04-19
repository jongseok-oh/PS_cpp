class Solution {
    int cnt[256];
public:
    int longestPalindrome(string s) {
        for(char c : s) cnt[c]++;

        int ret = 0; bool odd = false;
        for(int i = 0; i<256; ++i){
            ret += cnt[i]/2*2;
            odd |= cnt[i]&1;
        }

        return ret + odd;
    }
};