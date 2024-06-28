#include <string>
#include <vector>
#include <iostream>

using namespace std;

void print(vector<vector<int>>& matrix){
    for(int i = 0; i<64; ++i) for(int j = 0; j<64; ++j)
        cout<<matrix[i][j]<<(j==63?"\n":" ");
}

const int MOD = 1e9 + 7;
vector<vector<int>> _empty(64, vector<int>(64));

vector<vector<int>> multMatrix(vector<vector<int>>& a, vector<vector<int>>& b){
    vector<vector<int>> t = _empty;
    for(int i = 0; i<64; ++i){
        for(int j = 0; j<64; ++j){
            for(int k = 0; k<64; ++k){
                t[i][j] += (long long)a[i][k] * b[k][j] % MOD;
                t[i][j] %= MOD;
            }
        }
    }
    return t;
}

const int dy[] = {1,-1,0,0}, dx[] = {0,0,1,-1};
vector<vector<int>> makeDefaultMatrix(vector<vector<int>>& grid, vector<int>& d){
    int n = grid.size(), m = grid[0].size();
    
    vector<vector<int>> matrix = _empty;
    for(int i = 0; i<64; ++i) matrix[i][i] = 1;
    
    for(int diff: d){
        vector<vector<int>> t = _empty;
        for(int i = 0; i<n; ++i){
            for(int j = 0; j<m; ++j){
                for(int dir = 0; dir<4; ++dir){
                    int ny = i + dy[dir], nx = j + dx[dir];
                    if(ny < 0 || ny >= n || nx < 0 || nx >=m) continue;
                    if(grid[ny][nx] - grid[i][j] == diff){
                        t[i*8 + j][ny*8 + nx]++;
                    }
                }
            }
        }
        matrix = multMatrix(matrix, t);
    }
    return matrix;
}

int solution(vector<vector<int>> grid, vector<int> d, int k) {
    vector<vector<int>> df = makeDefaultMatrix(grid, d);
    vector<vector<int>> ret = _empty;
    for(int i = 0; i<64; ++i) ret[i][i] = 1;
    
    while(k){
        if(k&1) ret = multMatrix(ret, df);
        df = multMatrix(df, df);
        k >>=1;
    }
    
    int ans = 0;
    for(int i = 0; i<64; ++i){
        for(int j = 0; j<64; ++j){
            ans += ret[i][j];
            ans %= MOD;
        }
    }
    
    return ans;
}