#include <iostream>
#include <math.h>

using namespace std;

int n, m;

int memory[100], cost[100];

int cache[10001] = {0,};

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) cin >> memory[i];
	for (int i = 0; i < n; i++) cin >> cost[i];

	int maxCost = cost[0];
	cache[cost[0]] = memory[0];

	for (int idx = 1; idx < n; idx++) {
		maxCost += cost[idx];
		for (int tc = maxCost; tc >= cost[idx]; --tc) {
			cache[tc] = max(cache[tc], cache[tc - cost[idx]] + memory[idx]);
		}
	}

	for (int i = 0; i <= maxCost; i++) if (cache[i] >= m) { cout << i; return 0;}
}