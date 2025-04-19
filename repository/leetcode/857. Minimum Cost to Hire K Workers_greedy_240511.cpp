class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        
        vector<pair<double, int>> ratios(n);
        for(int i = 0; i<n; ++i)
            ratios[i] = {1.0 * wage[i]/quality[i] ,i};

        sort(begin(ratios), end(ratios));

        int qSum = 0;
        priority_queue<int> qHeap;
        // 가성비맨들로 드림팀 구성
        for(int i = 0; i<k; ++i){
            auto [ratio, idx] = ratios[i];
            qHeap.push(quality[idx]);
            qSum += quality[idx];
        }

        double maxRatio = ratios[k-1].first, ret = maxRatio * qSum;

        // 드림팀 중 고성과자 제외해보기
        for(int i = k; i<n; ++i){
            auto [ratio, idx] = ratios[i];
            qSum = qSum - qHeap.top() + quality[idx];
            qHeap.pop(); qHeap.push(quality[idx]);
            maxRatio = ratio;

            ret = min(ret, maxRatio * qSum);
        }

        return ret;
    }
};