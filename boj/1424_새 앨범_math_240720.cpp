#include <iostream>

using namespace std;

int n,l,c;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> l >> c;
    int maxSong = (c + 1) / (l + 1);
    if (maxSong % 13 == 0) maxSong--;
    int ret = n / maxSong;
    int remain = n % maxSong;
    if (remain) {
        if (remain % 13 == 0) {
            if (ret == 0) {
                ret += 2;
            }
            else {
                int help;
                if (maxSong % 13 == 1) help = 2;
                else help = 1;

                if (remain + help <= maxSong) ret += 1;
                else ret += 2;
            }
        }
        else ret += 1;
    }
    cout << ret;
}