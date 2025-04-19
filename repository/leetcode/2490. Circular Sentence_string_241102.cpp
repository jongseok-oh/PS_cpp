class Solution {
    vector<string> split(string& s, char del){
        istringstream iss(s);
        string buffer;

        vector<string> ret;
        while (getline(iss, buffer, del)) {
            ret.push_back(buffer);
        }
        return ret;
    }
public:
    bool isCircularSentence(string sentence) {
        vector<string> sentences = split(sentence, ' ');

        for(int i = 0, n = sentences.size(); i<n; ++i){
            char end = sentences[i].back();
            char start = sentences[(i+1)%n].front();
            if(end != start) return false;
        }
        return true;
    }
};