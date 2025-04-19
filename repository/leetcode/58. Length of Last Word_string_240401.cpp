class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int endIdx = n-1;
        while(s[endIdx] == ' ') --endIdx;

        int startIdx = endIdx;
        while(startIdx>=0 && s[startIdx] != ' ') --startIdx;

        return endIdx - startIdx;
    }
};