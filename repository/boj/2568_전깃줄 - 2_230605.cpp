#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;

struct Line{
	int a, b;
}lines[100000];

int arr[100001];
int cache[100000];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> lines[i].a >> lines[i].b;

	sort(lines, lines + n, [](const Line& a, const Line& b) {
		return a.a < b.a;
	});

	int size = 0;

	for (int i = 0; i < n; i++) {
		int tar = lines[i].b;

		int left = -1, right = size;
		while (left + 1 < right)
		{
			int mid = (left + right) >> 1;

			if (arr[mid] >= tar) right = mid;
			else left = mid;
		}
		
		if (right == size) arr[size++] = tar;
		else arr[right] = tar;

		cache[i] = right + 1;
	}

	cout << n - size << "\n";

	int tLen = size, tMaxLineNum = 1e9;
	vector<int> deletedLine;
	for (int i = n - 1; i >= 0; i--) {
		if (tLen == cache[i] && tMaxLineNum > lines[i].b) {
			tLen--; tMaxLineNum = lines[i].b;
		}
		else deletedLine.push_back(i);
	}

	for (auto it = deletedLine.rbegin(); it != deletedLine.rend(); it++) {
		cout << lines[*it].a << "\n";
	}
}