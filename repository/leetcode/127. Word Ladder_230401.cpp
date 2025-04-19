class Solution {
public:

    bool alphaConsist[10][26];
    unordered_map<string, bool> wordConsist;
    unordered_map<string, bool> wordVisit;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        for(string& word: wordList){
            wordConsist[word] = true;

            for(int i = 0, len = word.size(); i<len; i++)
                alphaConsist[i][word[i]-'a'] = true;
        }

        queue<string> q;
        q.push(beginWord);
        wordVisit[beginWord] = true;

        int ans = 0;
        while(q.size()){
            int qsize = q.size();

            while(qsize--){
                string t = q.front(); q.pop();

                if(t == endWord) return ans + 1;
                for(int i = 0, len = t.size(); i<len; i++){
                    string next = t;
                    for(int alpha = 0; alpha<26; alpha++){
                        if(alphaConsist[i][alpha]){
                            next[i] = alpha + 'a';
                            
                            if(wordConsist.find(next) != wordConsist.end()
                            && wordVisit.find(next) == wordVisit.end()){
                                wordVisit[next] = true;
                                q.push(next);
                            }
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};