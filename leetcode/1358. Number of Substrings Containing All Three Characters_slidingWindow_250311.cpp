class Solution {
    vector<int> cnt = vector<int>(3);
    bool isAtLeast(){
        return cnt[0] && cnt[1] && cnt[2];
    }
public:
    int numberOfSubstrings(string s) {
        int ret = 0;
        for(int i = 0, j = 0, n = s.size(); i<n; ++i){
            while(j<n && !isAtLeast()){
                ++cnt[s[j++] - 'a'];
            }
            if(isAtLeast()) ret += n - j + 1;
            --cnt[s[i] - 'a'];
        }
        return ret;
    }
};