class Solution {
    using ll = long long;
    bool isVowel(char c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    ll atLeastK(string word, int k){
        int consonantCnt = 0;
        unordered_map<char, int> vowelCnt;
        ll ret = 0;
        for(int i = 0, j = 0, n = word.size(); i<n; ++i){
            while(j < n && (vowelCnt.size() < 5 || consonantCnt < k)){
                char c = word[j++];
                if(isVowel(c)) ++vowelCnt[c];
                else ++consonantCnt;
            }

            if(vowelCnt.size() == 5 && consonantCnt >= k){
                ret += n - j + 1;
            }

            char c = word[i];
            if(isVowel(c)){
                if(--vowelCnt[c] == 0){
                    vowelCnt.erase(c);
                }
            }else --consonantCnt;
        }
        return ret;
    }
public:
    ll countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};