int left, right, tJoker;

int cards[100005];

struct 
{
	int begin, end;
	int arr[100005];
}_sum[20][20];


void _update(int idx, bool dir) {
	if (dir) {
		int jockerCnt = 0, sum = 0;
		for (int i = 0; i < 4; i++)
			if (cards[idx + i] == -1) jockerCnt++;
			else sum += cards[idx + i];

		for (int jocky = 0; jocky < 20; jocky++) {
			int tsum = (sum + jockerCnt * jocky) % 20;
			
			int& tend = _sum[tsum][jocky].end;
			_sum[tsum][jocky].arr[tend++] = idx;
		}
	}
	else {
		int jockerCnt = 0, sum = 0;
		for (int i = 0; i < 4; i++)
			if (cards[idx + i] == -1) jockerCnt++;
			else sum += cards[idx + i];

		for (int jocky = 0; jocky < 20; jocky++) {
			int tsum = (sum + jockerCnt * jocky) % 20;

			int& tbegin = _sum[tsum][jocky].begin;
			_sum[tsum][jocky].arr[tbegin--] = idx;
		}
	}
}

void init(int mJoker, int mNumbers[5])
{
	left = 50005, right = 50006, tJoker = mJoker % 20;

	for (int i = 0; i < 20; i++) for (int j = 0; j < 20; j++)
	{
		_sum[i][j].begin = 50005;
		_sum[i][j].end = 50006;
	}
	for (int i = 0; i < 5; i++) cards[right + i] = mNumbers[i];
	
	_update(right, true);
	_update(right + 1, true);
	
	right += 5;
}

void putCards(int mDir, int mNumbers[5])
{
	if (mDir) {
		for (int i = 0; i < 5; i++) cards[i + right] = mNumbers[i];

		for (int i = 0; i < 5; i++) _update(right - 3 + i, true);
		right += 5;
	}
	else {
		for (int i = 0; i < 5; i++) cards[left - 4 + i] = mNumbers[i];
		for (int i = 0; i < 5; i++) _update(left - i, false);
		left -= 5;
	}
}

int findNumber(int mNum, int mNth, int ret[4])
{
	int tbegin = _sum[mNum][tJoker].begin;
	int tend = _sum[mNum][tJoker].end;

	if (tbegin + mNth < tend) {
		int idx = _sum[mNum][tJoker].arr[tbegin + mNth];
		for (int i = 0; i < 4; i++)
			ret[i] = cards[idx + i];
		return 1;
	}
	return 0;
}

void changeJoker(int mValue)
{
	tJoker = mValue % 20;
}