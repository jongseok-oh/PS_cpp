#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

const int dy[] = {1,1,1,0,0,0,-1,-1,-1};
const int dx[] = {-1,0,1,-1,0,1,-1,0,1};

int r,c;
int jy, jx;
string moveDir;

int crazyCnt[100][100];
int crazyTemp[100][100];

void crazyMove(int& y, int& x){
	int minDist = 1e9;

	int ty = y, tx = x;
	for(int dir = 0; dir<=8; ++dir){
		int ny = ty + dy[dir], nx = tx + dx[dir];
		int tDist = abs(jy - ny) + abs(jx - nx);
		if(tDist < minDist){
			minDist = tDist;
			y = ny; x = nx;
		}
	}
}

void copyBoard(){
	for(int i = 0; i<r; ++i) for(int j = 0; j<c; ++j)
		if(crazyTemp[i][j] == 1) crazyCnt[i][j] = crazyTemp[i][j];
}
void printBoard(){
	for(int i = 0; i<r; ++i){
		for(int j = 0; j<c; ++j){
			if(i == jy && j == jx) cout<<'I';
			else if(crazyCnt[i][j]) cout<<'R';
			else cout<<'.';
		}
		cout<<"\n";
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>r>>c;
	char cc;
	for(int i = 0; i<r; ++i) for(int j = 0; j<c; ++j){
		cin>>cc;
		if(cc == 'I') {
			jy = i; jx = j;
		}else if(cc == 'R') crazyCnt[i][j] = 1;
	}
	cin>>moveDir;

	int moveCnt = 1;
	for(char mDir : moveDir){
		int tDir = mDir - '1';

		jy = jy + dy[tDir], jx = jx + dx[tDir];

		if(crazyCnt[jy][jx]) {cout<<"kraj "<<moveCnt;return 0;}

		memset(crazyTemp, 0, sizeof crazyTemp);
		for(int i = 0; i<r; ++i) for(int j = 0; j<c; ++j){
			if(crazyCnt[i][j]){
				int cy = i, cx = j;
				crazyMove(cy, cx);
				if(cy == jy && cx == jx) {cout<<"kraj "<<moveCnt;return 0;}
				crazyTemp[cy][cx]++;
				crazyCnt[i][j] = 0;
			}
		}
		copyBoard();
        moveCnt++;
	}
	printBoard();
	return 0;
}