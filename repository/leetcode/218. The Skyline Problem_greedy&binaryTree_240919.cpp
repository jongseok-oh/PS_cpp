class Solution {
    struct Line{int idx, height;};
    using pii = pair<int, int>;
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Line> lines;
        for(int i = 0, n = buildings.size(); i<n; ++i){
            const auto& building = buildings[i];

            int x1 = building[0], x2 = building[1];
            int height = building[2];
            
            lines.push_back({i, height});
            lines.push_back({i, -height});
        }

        sort(lines.begin(), lines.end(), [&](Line& l1, Line& l2){
            int x1 = l1.height < 0?buildings[l1.idx][1]:buildings[l1.idx][0];
            int x2 = l2.height < 0?buildings[l2.idx][1]:buildings[l2.idx][0];
            return x1 < x2 || (x1 == x2 && l1.height > l2.height);
        });

        vector<vector<int>> ret;

        // the heights of building's start line
        multiset<pii> heights;
        heights.insert({0, -1});
        
        int n = lines.size();
        for(int i = 0; i<n; ++i){
            const auto& [idx, height] = lines[i];
            // start line
            if(height > 0){
                int maxHeight = heights.rbegin()->first;
                if(maxHeight < height){
                    ret.push_back({buildings[idx][0], height});
                }
                heights.insert({height, idx});
            }else{
                // end line
                // remove end line's start line
                heights.erase({-height, idx});

                int maxHeight = heights.rbegin()->first;
                if(maxHeight < -height){
                    ret.push_back({buildings[idx][1], maxHeight});
                }
            }
        }

        return ret;
    }
};