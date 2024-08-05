class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> cnts;
        for(string& str: arr) cnts[str]++;
        for(string& str: arr){
            if(cnts[str] == 1) --k;
            if(k == 0) return str;
        }
        return "";
    }
};