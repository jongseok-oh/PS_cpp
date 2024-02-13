class Solution {
    bool isPalindrom(string& word){
        int n = word.size();
        for(int i = 0; i<n/2; ++i)
            if(word[i] != word[n-i-1]) return false;
        return true;
    }
public:
    string firstPalindrome(vector<string>& words) {
        for(string& word: words)
            if(isPalindrom(word)) return word;
        return "";
    }
};