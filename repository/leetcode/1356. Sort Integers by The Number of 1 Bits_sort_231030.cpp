class Solution {
    int cntBit(int num){
        int cnt = 0;
        while(num){
            cnt += num&1;
            num>>=1;
        }
        return cnt;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [&](const int& a, const int& b){
            int cnta = cntBit(a), cntb = cntBit(b);
            return cnta < cntb || (cnta == cntb && a< b);
        });
        return arr;
    }
};