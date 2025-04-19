#include <iostream>
#include <algorithm>

using namespace std;

struct pii {
	int skill, idx;
};

int n;

pii skills[500000];

bool cmpS(pii& a, pii& b) {
	return a.skill < b.skill;
}

int cSkills[500000];

int tree[2000000];

int tar;

int Query(int node, int left, int right) {
	if (right < tar) return 0;
	if (tar <= left && n - 1 >=right) return tree[node];
	int mid = (left + right) >> 1;
	return Query(node * 2, left, mid) + Query(node * 2 + 1, mid + 1, right);
}

void Update(int node, int left, int right) {
	if (left > tar || right < tar) return;
	if (left == right) {
		tree[node]++; return;
	}
	int mid = (left + right) >> 1;
	Update(node * 2, left, mid);
	Update(node * 2 + 1, mid + 1, right);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> skills[i].skill;
		skills[i].idx = i;
	}
	sort(skills, skills + n, cmpS);
	for (int i = 0; i < n; i++) cSkills[skills[i].idx] = i;

	for (int i = 0; i < n; i++) {
		tar = cSkills[i];
		cout << 1 + Query(1, 0, n - 1)  << "\n";
		Update(1, 0, n - 1);
	}
}