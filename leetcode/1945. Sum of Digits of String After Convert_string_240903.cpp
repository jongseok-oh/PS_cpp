class Solution {
    string convert(string transform){
        int calc = 0;
        for(char c : transform){
            calc += c-'0';
        }
        return to_string(calc);
    }
public:
    int getLucky(string s, int k) {
        string converted;
        for(char c : s){
            converted += to_string((int)(c - 'a' + 1));
        }
        while(k--){
            converted = convert(converted);
        }
        return stoi(converted);
    }
};