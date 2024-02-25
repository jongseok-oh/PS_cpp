class Solution {
    int divisor[100001];
    int p[100001];

    int getP(int t){
        if(!p[t]) return t;
        return p[t] = getP(p[t]);
    }

    void merge(int a, int b){
        int aP = getP(a), bP = getP(b);

        if(aP == bP) return;
        if(aP < bP) p[bP] = aP;
        else p[aP] = bP;
    }

    void solve(int t, int idx){
        if(t == 1) return;

        if(!divisor[t]) divisor[t] = idx;
        else merge(divisor[t], idx);
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        int n = nums.size();

        for(int i = 1; i<= n; ++i){
            int num = nums[i-1];
            int div = 1;

            while(div * div <=num){
                if(num % div == 0){
                    int a = div, b = num/div;
                    solve(a, i);
                    if(a != b) solve(b, i);
                }
                div++;
            }
        }

        for(int i = 1; i<=n; ++i)
            if(getP(i) != 1) return false;

        return true;
    }
};