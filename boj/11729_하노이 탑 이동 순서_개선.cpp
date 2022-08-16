#include <cstdio>
char buffer[1 << 22];
int idx = 0;

// 구조체로 만들어 후에 sequantial search로 출력하는 것이 아닌
// char buffer에 잔뜩 써두고 한 번에 출력
// 128ms -> 8ms

void hanoi(int num, int from, int to) {
	if (num == 0) return;
	hanoi(num - 1, from, to ^ from);
	buffer[idx++] = from + '0';
	buffer[idx++] = ' ';
	buffer[idx++] = to + '0';
	buffer[idx++] = '\n';
	hanoi(num - 1, to ^ from, to);
}
int main(void) {
	int n; scanf("%d", &n);
	hanoi(n, 1, 3);
	printf("%d\n", (1 << n) - 1);
	puts(buffer);
}