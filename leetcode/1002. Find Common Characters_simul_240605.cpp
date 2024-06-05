class Solution {
    int cnt[26][100];
public:
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        for(int idx = 0; idx < n; ++idx){
            string& word = words[idx];
            for(char c : word) ++cnt[c-'a'][idx];
        }

        vector<string> ret;

        for(int c = 0; c<26; ++c){
            int minCnt = *min_element(cnt[c], cnt[c] + n);
            
            while(minCnt--)
                ret.push_back(string {char(c+'a')});
        }
        return ret;
    }
};