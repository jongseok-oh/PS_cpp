class Solution {
    double dp[190][190];

    double solve(int a, int b){
        if(a <= 0 && b <= 0) return 0.5;
        if(a <= 0) return 1;
        if(b <= 0) return 0;

        auto& ret = dp[a][b];

        if(ret) return ret;

        ret += 0.25 * solve(a-4, b);
        ret += 0.25 * solve(a-3, b-1);
        ret += 0.25 * solve(a-2, b-2);
        ret += 0.25 * solve(a-1, b-3);

        return ret;
    }
public:
    double soupServings(int n) {
        if(n > 4800) return 1;
        n = (n + 24)/25;
        return solve(n,n);
    }
};