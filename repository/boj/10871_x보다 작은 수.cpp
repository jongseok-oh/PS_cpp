#include <iostream>

using namespace std;

int n, x;

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if (num < x) cout << num << " ";
	}
}
