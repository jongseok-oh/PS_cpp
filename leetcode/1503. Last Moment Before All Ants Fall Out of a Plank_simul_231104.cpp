class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int ret = 0;
        for(int& l: left) ret = max(ret, l);
        for(int& r: right) ret = max(ret, n-r);
        return ret;
    }
};