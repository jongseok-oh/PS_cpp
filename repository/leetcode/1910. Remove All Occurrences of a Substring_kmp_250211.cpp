class Solution {
    vector<int> failureFunction(string& part){
        int n = part.size();
        vector<int> fail(n);
        for(int i = 1; i<n; ++i){
            int len = fail[i - 1];
            while(len && part[i] != part[len]){
                len = fail[len-1];
            }
            if(part[i] == part[len]) ++len;
            fail[i] = len;
        }
        return fail;
    }
    string compress(string s, string& part, vector<int>& fail){
        int n = s.size(), m = part.size();
        string ret = "";
        for(int i = 0, len = 0; i<n; ++i){
            while(len && s[i] != part[len]){
                len = fail[len-1];
            }
            if(s[i] == part[len]) ++len;
            if(len == m){
                ret.resize(ret.size() - (m - 1));
                return compress(ret + s.substr(i+1), part, fail);
            }else ret.push_back(s[i]);
        }
        return ret;
    }
public:
    string removeOccurrences(string s, string part) {
        vector<int> fail = failureFunction(part);
        return compress(s, part, fail);
    }
};