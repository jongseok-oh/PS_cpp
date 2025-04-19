#include <iostream>

using namespace std;

int heap[100001];
int heapCnt;
int n;

void _swap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

void push(int num) {
	heap[++heapCnt] = num;
	int tnode = heapCnt;
	while (tnode != 1 && heap[tnode] > heap[tnode/2])
	{
		_swap(heap[tnode], heap[tnode / 2]);
		tnode /= 2;
	}
}

void pop() {
	cout << heap[1] << " ";
	heap[1] = heap[heapCnt];
	heap[heapCnt--] = 0;

	int tnode = 1;
	while (tnode *2 + 1 <= heapCnt && (heap[tnode] < heap[tnode * 2] || heap[tnode] < heap[tnode * 2 + 1])) {
		int bigger_node = heap[tnode * 2] > heap[tnode * 2 + 1] ? tnode * 2 : tnode * 2 + 1;
		_swap(heap[tnode], heap[bigger_node]);
		tnode = bigger_node;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cin >> n;
		cout << "#" << tt << " ";

		heapCnt = 0;
		
		for(int i =0; i<n; i++){
			int cmd;
			cin >> cmd;
			if (cmd == 1) {
				int num; cin >> num;
				push(num);
			}
			else {
				if (!heapCnt) cout << -1 << " ";
				else pop();
			}
		}
		cout << "\n";
	}
}