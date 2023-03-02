#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Node {
	int data;
	Node* next;
};

class list {
	Node node_pool[5000];
	int nodeCnt;
	Node* head; Node* tail;

public:
	list() {
		memset(node_pool, 0, sizeof(node_pool));
		nodeCnt = 0;
		head = 0; tail = 0;
	}

	Node* getNode(int data) {
		node_pool[nodeCnt] = { data, nullptr };
		return &node_pool[nodeCnt++];
	}

	void insert(int x, const vector<int>& s) {
		int st = 0;
		if (!x) {
			if (!head) { // 빈 리스트
				head = getNode(s[0]);
			}
			else {
				Node* tNode = getNode(s[0]);
				tNode->next = head;
				head = tNode;
			}
			st = 1;
			x = 1;
		}
		Node* cur = head;
		for (int i = 1; i < x; i++) cur = cur->next;
		for (int i = st, len = s.size(); i < len; i++) {
			Node* tNode = getNode(s[i]);
			tNode->next = cur->next;
			cur->next = tNode;
			cur = tNode;
		}
		if (!(cur->next)) tail = cur;
	}

	void remove(int x, int y) {
		if (!x) {
			Node* cur = head;
			for (int i = 0; i < y; i++) {
				cur = cur->next;
			}
			head = cur; return;
		}

		Node* cur = head;
		for (int i = 1; i < x; i++) cur = cur->next;

		Node* anchor = cur;
		for (int i = 0; i < y; i++) cur = cur->next;
		anchor->next = cur->next;

		if (!(cur->next)) tail = cur;
	}

	void add(int data) {
		Node* tnode = getNode(data);
		tail->next = tnode;
		tail = tnode;
	}
	void print() {
		int cnt = 10;
		Node* cur = head;
		while (cur && cnt--) {
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << "\n";
	}
};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int tt = 1; tt <= 10; tt++) {
		int n; cin >> n;
		list linkedList;

		vector<int> init(n);
		for (int i = 0; i < n; i++)  cin >> init[i];
		
		linkedList.insert(0, init);

		int m; cin >> m;
		while (m--)
		{
			char cmd; cin >> cmd;
			if (cmd == 'I') {
				int x, y; cin >> x >> y;
				vector<int> s(y);
				for (int i = 0; i < y; i++) cin >> s[i];
				linkedList.insert(x, s);
			}
			else if (cmd == 'D') {
				int x, y; cin >> x >> y;
				linkedList.remove(x, y);
			}
			else {
				int y; cin >> y;
				for (int i = 0; i < y; i++) {
					int data; cin >> data; 
					linkedList.add(data);
				}
			}
		}
		cout << "#" << tt << " "; linkedList.print();
	}
}
