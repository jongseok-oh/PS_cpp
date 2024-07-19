#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> prefixSum;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    prefixSum.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> prefixSum[i];
        if (i != 0) prefixSum[i] += prefixSum[i - 1];
    }
    int time;
    while (m--) {
        cin >> time;
        cout<< upper_bound(prefixSum.begin(), prefixSum.end(), time) - prefixSum.begin() <<"\n";
    }
}