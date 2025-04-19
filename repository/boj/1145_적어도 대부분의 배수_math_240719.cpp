#include <iostream>
#include <algorithm>

using namespace std;

int nums[5];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 0; i < 5; ++i) cin >> nums[i];

    int ret = 1e9;
    for (int i = 0; i < 5; ++i) for (int j = i + 1; j < 5; ++j) for (int k = j + 1; k < 5; ++k) {
        ret = min(ret, lcm(lcm(nums[i], nums[j]), nums[k]));
    }
    cout << ret;
}