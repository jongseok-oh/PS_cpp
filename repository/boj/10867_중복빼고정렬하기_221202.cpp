#include <iostream>
#include <set>

using namespace std;

int n;

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int num;
	set<int> s;
	while (n--) {
		cin >> num;
		s.insert(num);
	}
	for (int i : s) cout << i<<" ";
}