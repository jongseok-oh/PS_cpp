class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        for(int i = 0, n = str.size(); i<n/2; ++i){
            if(str[i] != str[n-1-i]) return false;
        }
        return true;
    }
};