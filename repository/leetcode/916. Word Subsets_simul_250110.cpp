class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxCnt(26);
        for(string& word : words2){
            vector<int> tCnt = cnt(word);
            for(int i = 0; i<26; ++i){
                maxCnt[i] = max(maxCnt[i], tCnt[i]);
            }
        }

        vector<string> ret;
        for(string& word : words1){
            vector<int> tcnt = cnt(word);
            bool isSubset = true;
            for(int i = 0; i<26; ++i){
                if(tcnt[i] < maxCnt[i]){
                    isSubset = false;
                    break;
                }
            }
            if(isSubset) ret.emplace_back(word);
        }

        return ret;
    }

    vector<int> cnt(string& word){
        vector<int> cnt(26);
        for(char c : word) ++cnt[c-'a'];
        return cnt;
    }
};