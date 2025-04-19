#include <iostream>
#include <algorithm>

using namespace std;

int num[3];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> num[0] >> num[1] >> num[2];
	sort(num, num + 3);
	cout<< num[0] <<" "<< num[1] <<" "<< num[2];
}