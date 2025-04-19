#include <unordered_map>
#include <string>

using namespace std;

short arr[10][200000];

unordered_map<string, int> sourceListIdxs;
int sourceCnt;

unordered_map<string, int> addressIdxs;
int addressCnt;

struct _log {
	int idx;
	short value;
}_logs[105500];

int logCnt;

int lastLog[6000];	// 주소지의 마지막 로그를 기록
int prevLog[105500];// 로그 역추적용 현재 로그 직전의 로그 저장

void init()
{
	sourceCnt = 0;
	addressCnt = 0;
	logCnt = 0;
}

void makeList(char mName[], int mLength, int mListValue[])
{
	string name(mName);
	for (int i = 0; i < mLength; i++) arr[sourceCnt][i] = mListValue[i];
	sourceListIdxs[name] = sourceCnt;

	addressIdxs[name] = addressCnt;		// 배열의 주소지 새로 생성

	_logs[logCnt] = { -1, (short)sourceCnt }; // 원본 배열 생성 로그 -> value에 source 배열을 저장
	lastLog[addressCnt] = logCnt;		// 방금 생성한 로그 -> 방금 생성한 주소지의 마지막 로그
	prevLog[logCnt] = -1;			// 앞 전 로그가 없다

	addressCnt++;
	sourceCnt++;
	logCnt++;
}

void copyList(char mDest[], char mSrc[], bool mCopy)
{
	string destName(mDest);
	string sourceName(mSrc);

	if (mCopy) {
		addressIdxs[destName] = addressCnt; // 배열 주소지 새로 생성

		int sourceAddress = addressIdxs[sourceName]; // 복사하려는 배열의 주소지

		_logs[logCnt] = { -1,-1 }; // 배열 복사 로그 생성

		int sourceLastLog = lastLog[sourceAddress]; // 복사하려는 배열의 마지막 로그

		prevLog[logCnt] = sourceLastLog;		// 원본 배열 마지막 로그와 연결
		
		lastLog[addressCnt] = logCnt; // 방금 생성한 복사 로그 -> 새로 생성한 주소의 마지막 로그

		addressCnt++;
		logCnt++;
	}
	else addressIdxs[destName] = addressIdxs[sourceName];
}

void updateElement(char mName[], int mIndex, int mValue)
{
	string name(mName);
	int address = addressIdxs[name];	// 배열의 주소지
	int last_log = lastLog[address];	// 해당 배열의 마지막 로그
	_logs[logCnt] = { mIndex, (short)mValue }; // 업데이트 로그 생성
	prevLog[logCnt] = last_log;			// 방금 생성한 로그의 앞 -> 배열의 마지막 로그
	lastLog[address] = logCnt;			// 배열의 마지막 로그 갱신
	logCnt++;
}

int element(char mName[], int mIndex)
{
	string name(mName);
	int address = addressIdxs[name];	// 배열의 주소지

	int tLog = lastLog[address];

	while (prevLog[tLog] != -1) {		// 직전 로그가 없을 때 까지
		if (_logs[tLog].idx == mIndex) return _logs[tLog].value; // idx가 바뀐 마지막 로그
		tLog = prevLog[tLog];
	}

	// 모든 로그를 다봤는데 idx의 업데이트가 없었으면
	// 원본 배열의 값 리턴
	int source = _logs[tLog].value;
	return arr[source][mIndex];
}