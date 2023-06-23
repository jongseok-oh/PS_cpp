#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int _MAX = 8 * 300000 + 50;

const int ROOT = 1;
int unused = 2;

int isEnd[_MAX];
int nextNode[_MAX][26];
string words[300001];


// 매 보글마다 초기화 필요////////
string board[4];
bool wordFind[300001];

// 0으로 초기화
int findCnt, score, maxLen;

// 빈 문자열 초기화
string maxLenString;
////////////////////////////////

void boggleInit() {
	findCnt = score = maxLen = 0;
	maxLenString = "";
	memset(wordFind, 0, sizeof(wordFind));
}

void insert(string& s, int idx) {

	int cur = ROOT;

	for (char c : s) {
		int& next = nextNode[cur][c - 'A'];
		if (!next) next = unused++;
		cur = next;
	}
	isEnd[cur] = idx;
}


void calcScore(int stringIdx) {
	findCnt++;
	string& str = words[stringIdx];
	int size = str.size();

	if (size == 3 || size == 4) score += 1;
	else if (size == 5) score += 2;
	else if (size == 6) score += 3;
	else if (size == 7) score += 5;
	else if (size == 8) score += 11;

	if (maxLen < size) {
		maxLen = size; maxLenString = str;
	}
	else if (maxLen == size && maxLenString > str)
		maxLenString = str;
}

const int dy[] = { -1,-1,-1,0,1,1,1,0}, dx[] = {-1,0,1,1,1,0,-1,-1};

// 초기화
bool visit[4][4];
void dfs(int node, int y, int x) {
	
	if (isEnd[node] && !wordFind[isEnd[node]]) {
		wordFind[isEnd[node]] = true;
		calcScore(isEnd[node]);
	}

	for (int dir = 0; dir < 8; dir++) {
		int ny = y + dy[dir];
		int nx = x + dx[dir];

		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || visit[ny][nx]) continue;
		
		int nNode = nextNode[node][board[ny][nx] - 'A'];
		if (nNode) {
			visit[ny][nx] = true;
			dfs(nNode, ny, nx);
			visit[ny][nx] = false;
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int w; cin >> w;

	for(int i = 1; i<=w; i++){
		cin >> words[i];
		insert(words[i], i);
	}
	
	int b; cin >> b;
	while (b--) {
		for (int i = 0; i < 4; i++) cin >> board[i];
		
		boggleInit();

		for (int i = 0; i < 4; i++) for (int j = 0; j < 4; j++) {
			int tNode = nextNode[ROOT][board[i][j] - 'A'];
			if (tNode) {
				visit[i][j] = true;
				dfs(tNode, i, j);
				visit[i][j] = false;
			}
		}

		cout << score << " " << maxLenString << " " << findCnt << "\n";
	}
}