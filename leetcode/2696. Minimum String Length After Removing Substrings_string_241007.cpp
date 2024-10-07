class Solution {
    string compress(const string& s){
        string temp = "";
        for(int i = 0, n = s.size(); i<n; ++i){
            if(i == n -1
            || !((s[i] == 'A' && s[i+1] == 'B')
                || (s[i] == 'C' && s[i+1] == 'D'))
            ){
                temp.push_back(s[i]);
                
            }else ++i;
        }
        return temp;
    }
public:
    int minLength(string s) {
        while(true){
            int _size = s.size();
            if(_size < 2) return _size;
            s = compress(s);
            if(_size == s.size()) break;
        }
        return s.size();
    }
};