#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <functional>

using namespace std;

struct Q {
private:
    int begin = 0, end = 0;
    int* arr;
public:
    Q(int size) {
        this->arr = new int[size];
    }
    void push(int val) {
        arr[end++] = val;
    }
    int pop() {
        return arr[begin++];
    }
    int size() {
        return end - begin;
    }
    void reset() {
        begin = 0; end = 0;
    }
}q(10001);

char mode[] = { 'D', 'S', 'L', 'R' };
vector<function<int(int)>> calc = {
    [](int t) -> int {return t * 2 % 10000; },
    [](int t) -> int {return (t + 9999) % 10000; },
    [](int t) -> int {return t % 1000 * 10 + t / 1000; },
    [](int t) -> int {return t / 10 + t % 10 * 1000; }
};

int p[10001];
char prevm[10001];
string bfs(int a, int b) {
    memset(p, -1, sizeof p);
    q.reset();
    q.push(a);

    while (q.size()) {
        int t = q.pop();
        if (t == b) break;
        
        for (int i = 0; i < 4; ++i) {
            int num = calc[i](t);
            if (p[num] == -1) {
                p[num] = t;
                prevm[num] = mode[i];
                q.push(num);
            }
        }
    }
    
    string ret = "";
    for (int v = b; v != a; v = p[v]) {
        ret += prevm[v];
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T,a,b; cin >> T;
    while (T--) {
        cin >> a >> b;
        cout << bfs(a, b) << "\n";
    }
}