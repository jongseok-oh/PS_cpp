class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<int> st1, st2;

        for(char& c: s){
            if(c != '#') st1.push_back(c);
            else if(st1.size()) st1.pop_back();
        }

        for(char& c: t){
            if(c != '#') st2.push_back(c);
            else if(st2.size()) st2.pop_back();
        }

        if(st1.size() != st2.size()) return false;

        for(int i = 0; i<st1.size(); ++i)
            if(st1[i] != st2[i]) return false;
        
        return true;
    }
};