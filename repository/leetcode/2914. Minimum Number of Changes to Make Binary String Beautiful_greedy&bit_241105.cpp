class Solution {
public:
    int minChanges(string s) {
        int n = s.size(), ret = 0;
        for(int i = 0; i<n; i += 2){
            ret += (s[i]- '0') ^ (s[i+1]- '0');
        }
        return ret;
    }
};