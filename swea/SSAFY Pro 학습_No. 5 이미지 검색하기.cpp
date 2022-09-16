#define MAX_N (10000)
#define MAX_M (10)

int _N, _M;

int Images[MAX_N][MAX_M];

int oneCnt[1 << MAX_M];

int startCache = 0;

int calcOneCnt(int num) {
	int q = 0;
	for (; num != 0; q++) num &= (num - 1);
	return q;
}

void init(int N, int M, char mImageList[MAX_N][MAX_M][MAX_M])
{
	_N = N; _M = M;

	for (int i = startCache, len = (1 << _M); i < len; i++)
		oneCnt[i] = calcOneCnt(i);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num = 0;
			for (int k = 0; k < M; k++) {
				if (mImageList[i][j][k]) num |= (1 << k);
			}
			Images[i][j] = num;
		}
	}
	startCache = (1 << _M);
}
int findImage(char mImage[MAX_M][MAX_M])
{
	int tImage[MAX_M];

	for (int i = 0; i < _M; i++) {
		int num = 0;
		for (int j = 0; j < _M; j++)
			if (mImage[i][j]) num |= (1 << j);
		tImage[i] = num;
	}

	int _maxSame = -1, tId = -1;

	for (int i = 0; i < _N; i++) {
		int tDiff = 0;
		for (int j = 0; j < _M; j++) {
			int tNum = Images[i][j] ^ tImage[j];
			tDiff += oneCnt[tNum];
		}
		int tSame = _M * _M - tDiff;
		if (tSame > _maxSame) {
			_maxSame = tSame;
			tId = i + 1;
		}
	}
	return tId;
}