class Solution {
    int getMult(string& s, int& j, int n){
        int mult = 0;
        while(j<n){
            char c = s[j];
            if(c >= '0' && c <= '9'){
                mult = mult * 10 + (c - '0');
                ++j;
            }else break;
        }
        return mult?mult:1;
    }
    unordered_map<string, int> parse(string s){
        unordered_map<string, int> ret;
        int n = s.size();
        for(int i = 0; i<n;){
            if(s[i] == '('){
                int j = i + 1, cnt = 1;
                while(j<n && cnt){
                    if(s[j] == '(') ++cnt;
                    else if(s[j] == ')') --cnt;
                    ++j;
                }
                auto temp = parse(s.substr(i + 1, j - i - 2));
                int mult = getMult(s, j, n);
                for(auto& [k, v] : temp) ret[k] += v * mult;
                i = j;
            }else{
                int j = i + 1;
                string key; key += s[i];
                while(j < n){
                    char c = s[j];
                    if(c >= 'a' && c <= 'z'){
                        key += c; ++j;
                    }else break;
                }
                ret[key] += getMult(s, j, n);
                i = j;
            }
        }
        return ret;
    }
public:
    string countOfAtoms(string formula) {
        auto atoms = parse(formula);
        vector<pair<string, int>> vec;
        vec.assign(atoms.begin(), atoms.end());
        sort(vec.begin(), vec.end());

        string ret;
        for(auto& [k,v] : vec){
            ret += k;
            if(v > 1) ret += to_string(v);
        }
        return ret;
    }
};