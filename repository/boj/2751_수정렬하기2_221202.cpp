#include <iostream>

using namespace std;
int n;
bool nums[2000050];

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;

	int num;
	while (n--) {
		cin >> num;
		nums[num + 1000000] = true;
	}

	for (int i = 0; i < 2000050; i++)
		if (nums[i])cout << i - 1000000 << "\n";
}