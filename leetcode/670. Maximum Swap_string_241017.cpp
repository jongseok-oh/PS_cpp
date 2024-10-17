class Solution {
    string swapString(int i, int j, string& str){
        string t = str;
        swap(t[i], t[j]);
        return t;
    }
public:
    int maximumSwap(int num) {
        string str = to_string(num), ret = str;
        for(int i = 0, n = str.size(); i<n-1; ++i){
            for(int j = i + 1; j<n; ++j){
                string temp = swapString(i, j, str);
                if(temp > ret) ret = temp;
            }
        }
        return stoi(ret);
    }
};