class Solution {
public:
    string sortVowels(string s) {
        vector<int> vowelIdx;
        vector<char> vowels;
        int n = s.size();
        for(int i = 0; i<n; ++i){
            if(isVowel(s[i])){
                vowelIdx.push_back(i);
                vowels.push_back(s[i]);
            }
        }

        sort(vowels.begin(), vowels.end());

        for(int i = 0; i<vowelIdx.size(); ++i)
            s[vowelIdx[i]] = vowels[i];
        
        return s;
    }

    bool isVowel(char& c){
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
};