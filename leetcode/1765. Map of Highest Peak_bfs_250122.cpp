class Solution {
    using pii = pair<int, int>;
    int dy[4] = {1,-1,0,0}, dx[4] = {0,0,1,-1};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();

        vector<vector<int>> ret(n, vector<int>(m, -1));

        queue<pii> q;
        for(int i = 0; i<n; ++i){
            for(int j =0;j<m; ++j){
                if(isWater[i][j]){
                    ret[i][j] = 0;
                    q.emplace(i, j);
                }
            }
        }

        int height = 1;
        while(q.size()){
            int qsize = q.size();
            while(qsize--){
                auto [y, x] = q.front(); q.pop();

                for(int dir = 0; dir<4; ++dir){
                    int ny = y + dy[dir], nx = x + dx[dir];
                    if(ny <0 || ny >= n || nx <0 || nx >= m || ret[ny][nx] != -1){
                        continue;
                    }
                    ret[ny][nx] = height;
                    q.emplace(ny,nx);
                }
            }
            ++height;
        }

        return ret;
    }
};