class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        for(int i = 0, n = word.size(); i<n;){
            char c = word[i];
            int cnt = 1;
            for(int j = i + 1; j<n; ++j){
                if(c == word[j]){
                    ++cnt;
                }else break;
            }
            
            int quotient = cnt/9;
            int remainder = cnt%9;
            
            while(quotient--){
                comp.push_back('0' + 9);
                comp.push_back(c);
            }

            if(remainder){
                comp.push_back('0' + remainder);
                comp.push_back(c);
            }

            i += cnt;
        }
        return comp;
    }
};