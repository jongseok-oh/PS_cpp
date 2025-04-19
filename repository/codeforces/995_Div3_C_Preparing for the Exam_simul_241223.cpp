#include <iostream>
#include <vector>
#include <string>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        vector<int> exam(m), knows(k);
        for (int& e : exam) cin >> e;
 
        vector<bool> dontKnow(n + 1, true);
        int know;
        for (int i = 0; i < k; ++i) {
            cin >> know;
            dontKnow[know] = false;
        }
        
        if (k < n - 1) {
            cout << string(m, '0') << "\n";
            continue;
        }
 
        for (int e : exam) {
            cout << (k == n || dontKnow[e]);
        }
        cout << "\n";
    }
}