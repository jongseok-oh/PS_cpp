class Solution {
    vector<string> split(string& str){
        vector<string> ret;
        string buffer;
        istringstream iss(str);
        while (getline(iss, buffer, ' ')) {
            ret.push_back(buffer);              
        }

        return ret;
    }
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> strs = split(sentence);
        for(int i = 0; i<strs.size(); ++i){
            string temp = strs[i];
            if(temp.size() < searchWord.size()) continue;
            
            bool find = true;
            for(int j = 0; j<searchWord.size(); ++j){
                if(temp[j] != searchWord[j]){
                    find = false;
                    break;
                }
            }
            if(find) return i + 1;
        }
        return -1;
    }
};