class Solution {
    using ll = long long;

    bool chk(ll limit, int n, vector<int>& quantities){
        int needStore = 0;
        for(ll q : quantities){
            needStore += q / limit + (q % limit > 0);
        }
        return needStore <= n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        ll s = 0 , e = 1e10;
        while(s + 1 < e){
            ll mid = (s + e)>>1;
            if(chk(mid, n, quantities)) e = mid;
            else s = mid;
        }
        return e;
    }
};