class Solution {
    vector<int> getCnt(string& s){
        vector<int> cnt(26);
        for(char c : s) ++cnt[c -'a'];
        return cnt;
    }
public:
    bool areAlmostEqual(string s1, string s2) {
        int diffCnt = 0;
        for(int i = 0, n = s1.size(); i<n; ++i){
            diffCnt += s1[i] != s2[i];
        }

        return (diffCnt == 0 || diffCnt == 2) && getCnt(s1) == getCnt(s2);
    }
};