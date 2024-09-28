class Solution {
    int getLonggestPalindromeLength(const string& s){
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        string pattern = s + "#" + reversed;

        int n = pattern.size();
        vector<int> pi(n);

        for(int i = 1; i<n; ++i){
            int length = pi[i-1];
            while(length > 0 && pattern[i] != pattern[length]){
                length = pi[length - 1];
            }
            if(pattern[i] == pattern[length]){
                ++length;
            }
            pi[i] = length;
        }

        return pi.back();
    }
public:
    string shortestPalindrome(string s) {
        int length = getLonggestPalindromeLength(s);
        return string(s.rbegin(), s.rbegin() + (s.size() - length)) + s;
    }
};