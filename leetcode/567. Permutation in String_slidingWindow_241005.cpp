class Solution {
    bool equals(const vector<int>& a, const vector<int>& b){
        for(int i = 0; i<26; ++i){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        vector<int> cnt1(26), window(26);

        for(char c : s1) ++cnt1[c- 'a'];

        int n = s1.size();
        for(int i = 0; i<n-1; ++i){
            ++window[s2[i] - 'a'];
        }

        for(int i = n-1, m = s2.size(); i<m; ++i){
            ++window[s2[i] - 'a'];
            if(equals(cnt1, window)) return true;
            --window[s2[i - n + 1] - 'a'];
        }
        return false;
    }
};