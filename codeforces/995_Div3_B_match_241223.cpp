#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, a, b, c;
        cin >> n >> a >> b >> c;
        
        int ret = n / (a + b + c) * 3;
        int remain = n % (a + b + c);
        
        for (int t : {a, b, c}) {
            if (remain <= 0) break;
            ++ret;
            remain -= t;
        }
        cout << ret << "\n";
    }
}