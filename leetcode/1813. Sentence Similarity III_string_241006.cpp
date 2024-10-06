class Solution {
    vector<string> split(string str, char Delimiter) {
        istringstream iss(str);
        string buffer;
        
        vector<string> result;
        while (getline(iss, buffer, Delimiter)) {
            result.push_back(buffer);
        }
        return result;
    }
    template <typename T>
    void swap(T& x, T& y) {
        T temp = x;
        x = y;
        y = temp;
    }
    bool isPrefix(vector<string> sub, vector<string>& big){
        int n = sub.size();
        for(int i = 0; i<n; ++i){
            if(sub[i] != big[i]){
                return false;
            }
        }
        return true;
    }
    bool isSuffix(vector<string> sub, vector<string>& big){
        int n = sub.size(), m = big.size();
        for(int i = n-1, j = m-1; i>=0; --i, --j){
            if(sub[i] != big[j]){
                return false;
            }
        }
        return true;
    }
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> small = split(sentence1, ' ');
        vector<string> big = split(sentence2, ' ');
        if(small.size() > big.size()) swap(small, big);
        
        for(int cnt = 0, n = small.size(); cnt<=n; ++cnt){
            if(isPrefix({small.begin(), small.begin() + cnt}, big)
            && isSuffix({small.begin() + cnt, small.end()}, big)){
                return true;
            }
        }
        return false;
    }
};