class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0, n = s.size(); i<n/2; ++i){
            char temp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = temp;
        }
    }
};