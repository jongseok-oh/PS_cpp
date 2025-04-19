#include <list>
#include <cstring>

using namespace std;

int _H, _W;

list<char> words[300];

list<char>::iterator cursor, endCursor;

int cursorRow;
int endCursorRow;

int prefix[300][26];

void init(int H, int W, char mStr[])
{
	// init
	_H = H; _W = W;

	for (int i = 0; i < 300; i++) words[i].clear();
	memset(prefix, 0, sizeof(prefix));

	int idx = 0;

	// 처음 글자 삽입
	int h;
	while (mStr[idx]) {
		h = idx / W;
		words[h].push_back(mStr[idx]);
		prefix[h][mStr[idx] - 'a']++;
		idx++;
	}
	cursor = words[0].begin();
	cursorRow = 0;
	endCursor = words[h].end();
	endCursorRow = h;
}

void insert(char mChar)
{
	words[cursorRow].insert(cursor, mChar);
	prefix[cursorRow][mChar - 'a']++;

	int tRow = cursorRow;

	// W 크기보다 넘쳤으면 다음 행에 넘겨 줌
	while (words[tRow].size() > _W) {
		words[tRow + 1].push_front(*(words[tRow].rbegin()));
		prefix[tRow + 1][*(words[tRow].rbegin()) - 'a']++;

		prefix[tRow][*(words[tRow].rbegin()) - 'a']--;

		
		if (tRow == cursorRow && words[cursorRow].size() > _W ){
			// cursor가 행의 마지막 앞일 때
			if (cursor == prev(words[cursorRow].end()))
				cursor = words[cursorRow].end();

			// 찐 마지막일 때
			else if (cursor == words[cursorRow].end())
			{
				cursor = next(words[cursorRow + 1].begin());
				cursorRow++;
			}
		}
		words[tRow].pop_back();

		tRow++;
	}

	endCursor = words[tRow].end();
	endCursorRow = tRow;
}

char moveCursor(int mRow, int mCol)
{
	mRow--; mCol--;

	auto b = words[mRow].begin();

	while (mCol > 0 && b != words[mRow].end()) {
		mCol--; b++;
	}

	if (b != words[mRow].end()) {
		cursor = b;
		cursorRow = mRow;
		return *b;
	}

	cursor = endCursor;
	cursorRow = endCursorRow;

	return '$';
}

int countCharacter(char mChar)
{
	int cnt = 0;
	for (auto it = words[cursorRow].begin(); it != cursor; it++) {
		if (*it == mChar) cnt++;
	}

	int sum = prefix[cursorRow][mChar - 'a'] - cnt;

	int tRow = cursorRow + 1;
	while (words[tRow].size())  sum += prefix[tRow++][mChar - 'a'];

	return sum;
}