class Solution {
    const int dy[4] = {1,0,-1,0}, dx[4] = {0,1,0,-1};
    int n,m;
    bool visit[6][6];

    bool solve(int y, int x, int idx, vector<vector<char>>& board, string& word){
        if(idx == word.size() -1 &&
        word[idx] == board[y][x]) return true;
        if(word[idx] != board[y][x]) return false;

        visit[y][x] = true;
        for(int dir = 0; dir<4; ++dir){
            int ny = y + dy[dir], nx = x + dx[dir];
            if(ny <0 || ny>=n || nx < 0 || nx >= m
            || visit[ny][nx]) continue;
            if(solve(ny,nx, idx + 1, board, word)){
                visit[y][x] = false;
                return true;
            }
        }
        visit[y][x] = false;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(); m = board[0].size();

        for(int i = 0; i<n; i++) for(int j = 0; j<m; ++j){
            if(solve(i,j,0,board,word))
                return true;
        }

        return false;
    }
};