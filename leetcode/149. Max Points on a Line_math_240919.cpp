class Solution {
    using tiii = tuple<int, int, int>;
    using pii = pair<int, int>;

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    tiii getLineEquation(int x1, int y1, int x2, int y2) {
        int a = y2 - y1;
        int b = x1 - x2;
        int c = a * x1 + b * y1;

        if (a < 0 || (a == 0 && b < 0)) {
            a = -a;
            b = -b;
            c = -c;
        }

        int divisor = gcd(gcd(abs(a), abs(b)), abs(c));

        if(divisor > 0){
            a /= divisor;
            b /= divisor;
            c /= divisor;
        }

        return {a, b, c};
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 1) return 1;

        map<pii, unordered_map<int, int>> lineCnt;
        for(int i = 0; i<n-1; ++i) for(int j = i+1; j<n; ++j){
            
            tiii line = getLineEquation(points[i][0], points[i][1], points[j][0], points[j][1]);
            auto [a, b, c] = line;
            lineCnt[{a,b}][c]++;
        }

        int ret = -1;
        for(const auto& [key, hashMap] : lineCnt){
            for(const auto& [c, cnt] : hashMap){
                ret = max(ret, cnt);
            }
        }

        return sqrt(ret * 2) + 1;
    }
};