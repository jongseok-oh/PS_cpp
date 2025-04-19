#include <iostream>

using namespace std;

int n;

// 좌 중 우
int inorder[100000];
int inorderIndx[100001];
// 좌 우 중
int postorder[100000];

void preorder(int inStart, int inEnd, int postStart, int postEnd) {
	cout << postorder[postEnd] << " ";

	if (postStart == postEnd) return;

	int i = inorderIndx[postorder[postEnd]];

	int leftLen = i - inStart, rightLen = inEnd - i;
	if(leftLen) preorder(inStart, i - 1, postStart, postStart + leftLen -1);
	if(rightLen) preorder(i + 1, inEnd, postStart + leftLen, postEnd - 1);

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> inorder[i];
		inorderIndx[inorder[i]] = i;
	}
	for (int i = 0; i < n; i++) cin >> postorder[i];

	// 중 좌 우 출력
	preorder(0, n - 1, 0, n - 1);
}