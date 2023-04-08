class Solution {
public:
    string strArr[1000];
    string convert(string s, int numRows) {

        bool mode = true;
        int tRow = 0;
        for(int i = 0, len = s.size(); i<len; i++){
            strArr[tRow].push_back(s[i]);
            if(tRow == 0) mode = true;
            else if(tRow == (numRows-1)) mode = false;
            if(numRows != 1)mode?tRow++:tRow--;
        }
        
        string ans;
        for(int i = 0; i<numRows; i++) ans += strArr[i];
        return ans;
    }
};