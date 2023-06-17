#include <iostream>

using namespace std;

int arr[2][2] = { {1,4},{2,3} };

int main() {
    int x, y;
    cin >> x >> y;

    cout << arr[x < 0][y < 0];
}