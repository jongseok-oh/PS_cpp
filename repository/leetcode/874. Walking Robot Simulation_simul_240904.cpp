class Solution {
    const int dy[4] = {1,0,-1,0};
    const int dx[4] = {0,1,0,-1};
    unordered_map<int, unordered_set<int>> obstacleSet;

    bool isObtacle(int y, int x){
        if(!obstacleSet.count(y)) return false;
        return obstacleSet[y].count(x);
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        for(auto& obstacle : obstacles){
            int x = obstacle[0], y = obstacle[1];
            obstacleSet[y].insert(x);
        }

        int dir = 0, ty = 0, tx = 0;
        int ret = 0;
        for(int comm : commands){
            if(comm == -1){
                dir = (dir + 1) % 4;
            }else if(comm == -2){
                dir = (dir + 3) % 4;
            }else{
                while(comm--){
                    int ny = ty + dy[dir], nx = tx + dx[dir];
                    if(isObtacle(ny,nx)) break;
                    ty = ny; tx = nx;
                }
            }
            ret = max(ret, ty * ty + tx * tx);
        }
        return ret;
    }
};