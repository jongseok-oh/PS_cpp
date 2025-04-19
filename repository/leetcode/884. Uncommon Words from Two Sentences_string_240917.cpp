class Solution {
    vector<string> split(const string& s, const string& delimiter) {
        vector<string> tokens;
        string token;
        istringstream tokenStream(s);
        while (getline(tokenStream, token, delimiter[0])) {
            tokens.push_back(token);
        }
        return tokens;
    }
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCnt;
        vector<string> words1 = split(s1, " ");
        vector<string> words2 = split(s2, " ");

        for(string& word : words1) ++wordCnt[word];
        for(string& word : words2)++wordCnt[word];

        vector<string> ret;
        for(auto [word, cnt] : wordCnt){
            if(cnt == 1) ret.emplace_back(word);
        }

        return ret;
    }
};