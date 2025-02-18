class Solution {
public:
    string getHappyString(int n, int k) {
        int _max = 1<<(n-1);
        if(k > 3 * _max) return "";

        --k;
        string ret(n, ' ');
        ret[0] = 'a' + k/_max;
        k %= _max;
        
        for(int i = 1; i<n; ++i){
            int cnt = 1<<(n-1-i);
            for(char c = 'a'; c<='c'; ++c){
                if(ret[i-1] == c) continue;
                ret[i] = c;
                if(k >= cnt) k -= cnt;
                else break;
            }
        }
        return ret;
    }
};