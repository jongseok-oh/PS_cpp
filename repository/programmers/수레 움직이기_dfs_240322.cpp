#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;

int dy[] = {1,0,-1,0} , dx[] = {0,1,0,-1};
bool bVisit[4][4], rVisit[4][4];

bool cantGo(int y, int x, vector<vector<int>>& maze, bool visit[][4]){
    return y <0 || y>=n || x < 0 || x >=m || maze[y][x] == 5 || visit[y][x];
}

int ret = 1e9;
void solve(int by, int bx, int ry, int rx, vector<vector<int>>& maze, int move){
    if(maze[by][bx] == 4 && maze[ry][rx] == 3){
        ret = min(ret, move);
        return;
    }
    
    int nby, nbx, nry, nrx;
    for(int bDir = 0; bDir<4; ++bDir){
        if(maze[by][bx] == 4){
            nby = by; nbx = bx;
        }else {
            nby = by + dy[bDir]; nbx = bx + dx[bDir];
            if(cantGo(nby, nbx, maze, bVisit)) continue;
        }
        
        for(int rDir = 0; rDir<4; ++rDir){
            if(maze[ry][rx] == 3){
                nry = ry; nrx = rx;
            }else{
                nry = ry + dy[rDir]; nrx = rx + dx[rDir];
                if(cantGo(nry, nrx, maze, rVisit)) continue;
            }
            
            if((nby == nry && nbx == nrx) || (by == nry && bx == nrx && ry == nby && rx == nbx)) continue;
            
            bVisit[nby][nbx] = true;
            rVisit[nry][nrx] = true;
            solve(nby, nbx, nry, nrx, maze, move + 1);
            bVisit[nby][nbx] = false;
            rVisit[nry][nrx] = false;
        }
    }
}

int solution(vector<vector<int>> maze) {
    n = maze.size(); m = maze[0].size();
    int by,bx,ry,rx;
    
    for(int i =0; i<n; ++i) for(int j = 0; j<m; ++j){
        int& t = maze[i][j];
        if(t == 1){
            ry = i; rx = j;
            t = 0;
        }else if(t == 2){
            by = i; bx = j;
            t = 0;
        }
    }
    bVisit[by][bx] = true; rVisit[ry][rx] = true;
    solve(by, bx, ry, rx, maze, 0);
    return (ret == 1e9?0:ret);
}