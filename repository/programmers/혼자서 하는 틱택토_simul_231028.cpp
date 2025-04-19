#include <string>
#include <vector>

using namespace std;

int checkWin(char c, vector<string>& board){
    
    int winCnt = 0;
    
    if(board[0][0] == c){
        if(board[0][1] == c && board[0][2] == c) winCnt++;
        if(board[1][1] == c && board[2][2] == c) winCnt++;
        if(board[1][0] == c && board[2][0] == c) winCnt++;
    }
    
    if(board[0][1] == c && board[1][1] == c && board[2][1] == c) winCnt++;
    
    if(board[0][2] == c){
        if(board[1][1] == c && board[2][0] == c) winCnt++;
        if(board[1][2] == c && board[2][2] == c) winCnt++;
    }
    
    if(board[1][0] == c && board[1][1] == c && board[1][2] == c) winCnt++;
    if(board[2][0] == c && board[2][1] == c && board[2][2] == c) winCnt++;
    
    return winCnt;
}

int solution(vector<string> board) {
    int oCnt = 0, xCnt = 0;
    
    for(auto& row: board) for(auto& loc : row)
        if(loc == 'O') ++oCnt;
        else if(loc == 'X') ++xCnt;

    if(oCnt != xCnt + 1 && oCnt != xCnt) return false;
    
    int oWinCnt = checkWin('O', board);
    int xWinCnt = checkWin('X', board);
   
    if(oWinCnt && (xWinCnt || oCnt != xCnt + 1)) return false;
    if(xWinCnt && (oWinCnt || oCnt != xCnt)) return false;
    
    return true;
}