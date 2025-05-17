class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26);
        for(char c : s) ++cnt[c -'a'];
        
        char center = '-';
        string left = "";
        for(int i = 0; i<26; ++i){
            if(cnt[i] == 0) continue;
            if(cnt[i] & 1) center = i + 'a';
            
            left += string(cnt[i]/2, i + 'a');
        }
        
        string ret = left;
        if(center != '-') ret.push_back(center);
        reverse(left.begin(), left.end());
        ret += left;
        
        return ret;
    }
};
