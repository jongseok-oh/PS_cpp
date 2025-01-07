class Solution {
    vector<int> failure(string& str){
        int n = str.size();
        vector<int> fail(n);
        for(int i = 1, len = 0; i<n; ++i){
            while(len != 0 && str[i] != str[len]){
                len = fail[len-1];
            }
            if(str[i] == str[len]) ++len;
            fail[i] = len;
        }
        return fail;
    }
    bool isMatch(string& a, string& b, vector<int>& fail){
        int n = a.size(), m = b.size();
        for(int i = 0, len = 0; i<n; ++i){
            while(len != 0 && a[i] != b[len]){
                len = fail[len-1];
            }
            if(a[i] == b[len]) ++len;
            if(len == m) return true;
        }
        return false;
    }
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        
        vector<string> ret;
        for(int i = 0; i<n; ++i){
            vector<int> fail = failure(words[i]);
            for(int j = 0; j<n; ++j){
                string a = words[i], b = words[j];
                if(i == j || a.size() > b.size()) continue;
                if(isMatch(b, a, fail)){
                    ret.emplace_back(a);
                    break;
                }
            }
        }

        return ret;
    }
};