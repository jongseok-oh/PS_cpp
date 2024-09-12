class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> allowedSet;
        for(char c : allowed){
            allowedSet.insert(c);
        }

        int ret = 0;
        for(string& word: words){
            bool allAlowed = true;
            for(char c : word){
                if(!allowedSet.count(c)){
                    allAlowed = false; break;
                }
            }
            if(allAlowed) ++ret;
        }

        return ret;
    }
};