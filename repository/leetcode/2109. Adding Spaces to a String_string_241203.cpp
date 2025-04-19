class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ret;
        int prev = 0;
        for(int space : spaces){
            ret += s.substr(prev, space - prev) + " ";
            prev = space;
        }
        ret += s.substr(prev);

        return ret;
    }
};