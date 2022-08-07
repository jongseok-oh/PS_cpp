#include <iostream>
#include <vector>

using namespace std;

int node[10000];

void pre(int start, int end) {
	if (start == end) return; // 오른쪽 혹은 왼쪽 자식이 없을 때
	if (start + 1 == end) { cout << node[start] << "\n"; return;} // leef node 일 때

	int p = node[start];

	int idx = start + 1;
	
	while (node[idx] < p && idx < end) idx++;
	
	pre(start + 1, idx);
	pre(idx, end);
	cout << p<<"\n";
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int num, idx = 0;
	while (cin >> num) {
		node[idx++] = num;
	}
	pre(0, idx);
}