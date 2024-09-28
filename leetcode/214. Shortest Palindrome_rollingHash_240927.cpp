class Solution {
    using ll = long long;
    int getLongestPalindromeLength(string& s){
        int prime = 31, mod = 1e9 + 7;
        ll hash = 0, revHash = 0, pow = 1;

        int ret = 1;
        for(int i = 0, n = s.size(); i<n; ++i){
            int val = s[i] - 'a' + 1;
            hash = (hash * prime + val) % mod;
            revHash = (pow * val + revHash) % mod;

            if(hash == revHash) ret = i + 1;
            pow = (pow * prime) % mod;
        }

        return ret;
    }
public:
    string shortestPalindrome(string s) {
        if(s.size() == 0) return s;
        
        int len = getLongestPalindromeLength(s);
        string rev = s.substr(len);
        reverse(rev.begin(), rev.end());
        return rev + s;
    }
};