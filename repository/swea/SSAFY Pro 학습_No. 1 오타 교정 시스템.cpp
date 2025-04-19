#include <cstring>
#include <unordered_map>
#include <vector>
#include <set>
#include <string>

using namespace std;

int _time[2001];

string wrong[2001];

unordered_map<string, unordered_map<string, set<int>>> candi;

unordered_map<string, vector<string>> db;

int check(string right, string wrong) {
	int rightLen = right.size(),
		wrongLen = wrong.size();
	
	// 치환 검사
	if (rightLen == wrongLen) {
		int diffCnt = 0;
		for (int i = 0; i < rightLen; i++) {
			if (right[i] != wrong[i]) diffCnt++;
			if (diffCnt > 1) break;
		}
		if (diffCnt == 1) return 0;
	}
	// 추가 검사
	else if (rightLen + 1 == wrongLen) {
		int idx = 0;
		while (idx < rightLen && right[idx] == wrong[idx])
			idx++;
		
		while (idx < rightLen && wrong[idx + 1] == right[idx]) idx++;
		if (idx == rightLen) return 1;
	}
	// 삭제 검사
	else if (rightLen == wrongLen + 1) {
		int idx = 0;
		while (idx < wrongLen && right[idx] == wrong[idx])
			idx++;

		while (idx < wrongLen && wrong[idx] == right[idx + 1]) idx++;
		if (idx == wrongLen) return -1;
	}

	return -2;
}

void init(int n) {
	memset(_time, -1, sizeof(int) * (n+1));
	candi.clear();
	db.clear();
	return;
}

int search(int mId, int searchTimestamp, char searchWord[11], char correctWord[5][11]) {
	string searchString(searchWord);

	int& pSearchTime = _time[mId];
	if (pSearchTime == -1 || (searchTimestamp - pSearchTime) > 10) {
		pSearchTime = searchTimestamp;
		wrong[mId] = searchString;
	}
	else {
		int mod = check(searchString, wrong[mId]);
		if (mod != -2) {
			if (candi[wrong[mId]][searchString].size() < 3) {
				candi[wrong[mId]][searchString].insert(mId);
				if (candi[wrong[mId]][searchString].size() >= 3) {
					db[wrong[mId]].push_back(searchString);
				}
			}
		}
		pSearchTime = -1;
	}

	if (db[searchString].size()) {
		int len = len = db[searchString].size();
		for (int i = 0; i < len; i++) {
			string t = db[searchString][i];
			for (int j = 0, strLen = t.size(); j < strLen; j++)
				correctWord[i][j] = t[j];
		}
		return len;
	}

	return 0;
}