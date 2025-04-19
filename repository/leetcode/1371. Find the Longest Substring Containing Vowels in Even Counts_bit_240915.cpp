class Solution {
    int vowelIdx[26];
    int convertVowelBit(char c, int bit){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
            bit ^= (1<<vowelIdx[c - 'a']);
        }
        return bit;
    }
public:
    int findTheLongestSubstring(string s) {
        vowelIdx['a' - 'a'] = 0;
        vowelIdx['e' - 'a'] = 1;
        vowelIdx['i' - 'a'] = 2;
        vowelIdx['o' - 'a'] = 3;
        vowelIdx['u' - 'a'] = 4;
        
        vector<int> cache(1<<5, -2);
        cache[0] = -1;
        int vowelBit = 0, ret = 0;
        for(int i = 0, n = s.size(); i<n; ++i){
            char c = s[i];
            vowelBit = convertVowelBit(c, vowelBit);
            if(cache[vowelBit] == -2){
                cache[vowelBit] = i;
            }
            
            ret = max(ret, i - cache[vowelBit]);
        }

        return ret;
    }
};