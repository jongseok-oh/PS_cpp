class Solution {
    void decrease(unordered_map<int, int>& map, int key){
        if(--map[key] == 0){
            map.erase(key);
        }
    }
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int n = queries.size();
        unordered_map<int, int> ballColors, colorCounts;

        vector<int> ret(n);
        for(int i = 0; i<n; ++i){
            auto& query = queries[i];
            int ball = query[0], color = query[1];

            if(ballColors.count(ball)){
                if(ballColors[ball] == color){
                    ret[i] = colorCounts.size();
                    continue;
                }
                int ballColor = ballColors[ball];
                decrease(colorCounts, ballColor);
                decrease(ballColors, ball);
            }
            ballColors[ball] = color;
            ++colorCounts[color];

            ret[i] = colorCounts.size();
        }

        return ret;
    }
};