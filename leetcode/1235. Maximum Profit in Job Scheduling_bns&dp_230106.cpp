class Solution {
    int dp[50001];
    struct Ei{int e,idx;};
public:
    int jobScheduling(vector<int>& s, vector<int>& e, vector<int>& p) {
        int n = p.size();
        vector<Ei> eis;
        for(int i = 0; i<n; ++i) eis.push_back({e[i], i});
        sort(eis.begin(), eis.end(), [&](Ei& a, Ei& b){
            return a.e < b.e;
        });

        for(int i = 0; i<n; ++i){
            // 앞 배열의 endTime이 현재 job의 startTime보다
            // 큰 것들 중 가장 앞에 있는 인덱스
            int lidx = upper_bound(eis.begin(), eis.begin()+i, s[eis[i].idx],
                [&](int sTime, Ei& t){return sTime < t.e;} // true인 것들 중 제일 앞의 iterator
            ) - eis.begin();

            // 실제 dp는 인덱스를 하나 더 큰것을 사용해서
            // 어떤 job도 놓이지 않은 상황처리
            // 실제 lidx -1(dp에선 lidx)은
            // 현재 job의 starTime보다 작은 endTime 중 제일 큰 값을 지닌 인덱스
            dp[i + 1] = max(dp[i], dp[lidx] + p[eis[i].idx]);
        }

        return dp[n];
    }
};