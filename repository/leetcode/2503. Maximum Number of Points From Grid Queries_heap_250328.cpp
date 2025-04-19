class Solution {
    using tiii = tuple<int, int, int>;
    const int dy[4] = {1,-1,0,0};
    const int dx[4] = {0,0,1,-1};
    struct Query{
        int value, idx;
    };
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int k = queries.size();
        vector<Query> sortedQueries;
        for(int i = 0; i<k; ++i){
            sortedQueries.push_back({queries[i], i});
        }
        sort(sortedQueries.begin(), sortedQueries.end(),[](auto& q1, auto& q2){
            return q1.value < q2.value;
        });

        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visit(n, vector<bool>(m));
        priority_queue<tiii, vector<tiii>, greater<>> q;
        q.emplace(grid[0][0], 0, 0);
        visit[0][0] = true;

        int point = 0;
        vector<int> ret(k);
        for(auto& [value, idx] : sortedQueries){
            while(q.size()){
                auto [val, y, x] = q.top();
                if(val >= value) break;
                ++point; q.pop();
                for(int dir = 0; dir<4; ++dir){
                    int ny = y + dy[dir], nx = x + dx[dir];
                    if(ny < 0 || ny >= n || nx < 0 || nx >= m
                    || visit[ny][nx]) continue;
                    visit[ny][nx] = true;
                    q.emplace(grid[ny][nx], ny, nx);
                }
            }
            ret[idx] = point;
        }
        
        return ret;
    }
};