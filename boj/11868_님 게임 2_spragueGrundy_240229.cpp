#include <iostream>

using namespace std;

int n;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    int stones, ret = 0;
    for(int i =0; i<n; ++i) {
        cin>>stones;
        ret ^= stones;
    }
    cout<<(!ret?"cubelover":"koosaga");
}