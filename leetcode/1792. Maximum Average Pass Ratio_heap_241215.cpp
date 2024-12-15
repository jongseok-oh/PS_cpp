class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto increaseRate = [](vector<int>& a){
            return 1.0 * (a[0] + 1) / (a[1] + 1) - 1.0 * a[0] / a[1];
        };
        auto cmp = [&increaseRate](vector<int>& a, vector<int>& b){
                return increaseRate(a) < increaseRate(b);
            };
        priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> q(cmp);

        for(auto& c : classes){
            q.emplace(c);
        }

        while(extraStudents--){
            auto minClass = q.top(); q.pop();
            ++minClass[0];
            ++minClass[1];
            q.emplace(minClass);
        }

        double sum = 0;
        while(q.size()){
            auto t = q.top(); q.pop();
            sum += 1.0 * t[0] / t[1];
        }

        return sum / classes.size();
    }
};