#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int data, Node* next) { this->data = data; this->next = next;}
};

Node* head;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		int n, m, l; cin >> n >> m >> l;

		head = nullptr;

		Node* cur;
		for (int i = 0; i < n; i++) {
			int data; cin >> data;
			if (!head) {
				head = new Node(data, 0);
				cur = head;
			}
			else {
				cur->next = new Node(data, 0);
				cur = cur->next;
			}
		}

		while (m--)
		{
			char cmd; cin >> cmd;
			
			int idx, data;
			switch (cmd)
			{
			case 'I':
				cin >> idx >> data;
				if (!idx) {
					Node* tNode = new Node(data, head);
					head = tNode;
				}
				else {
					Node* cur = head;
					for (int i = 1; i < idx; i++) cur = cur->next;
					Node* tnode = new Node(data, cur->next);
					cur->next = tnode;
				}
				break;
			case 'D':
				cin >> idx;
				if (!idx) {
					head = head->next;
				}
				else {
					Node* cur = head;
					for (int i = 1; i < idx; i++) cur = cur->next;
					Node* anchor = cur;
					anchor->next = cur->next->next;
				}
				break;
			case 'C':
				cin >> idx >> data;
				Node* cur = head;
				for (int i = 0; i < idx; i++) cur = cur->next;
				cur->data = data;
			}
		}

		while (head && l--) head = head->next;
		cout << "#" << tt << " " << (!head ? -1 : head->data) << "\n";
	}
}
