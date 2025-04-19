#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
struct Edge {
    int to;
    char flower;
};
vector<Edge> con[500001];

void makeTree() {
    int u, v; char flow;
    for (int i = 0; i < N - 1; ++i) {
        cin >> u >> v >> flow;
        con[u].push_back({ v,flow });
    }
}

vector<int> failureFunction(const string& P) {
    int n = P.size();
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int length = pi[i - 1];
        while (length > 0 && P[i] != P[length]) {
            length = pi[length - 1];
        }
        if (P[i] == P[length]) ++length;
        pi[i] = length;
    }
    return pi;
}

int dp[500000][26];
int calcMatchLen(int length, char c, const string& P, const vector<int>& pi) {
    int& ret = dp[length][c - 'a'];
    if (ret != -1) return ret;
    if (P[length] == c) return ret = length + 1;
    return ret = (length == 0 ? 0 : calcMatchLen(pi[length - 1], c, P, pi));
}

int solve(int node, int length, const string& P,const vector<int>& pi) {
    int ret = 0;
    for (const auto& [to, flower] : con[node]) {
        int tlen = calcMatchLen(length, flower, P, pi);
        if (tlen == P.size()) {
            ++ret;
            tlen = pi[tlen - 1];
        }
        ret += solve(to, tlen, P, pi);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    makeTree();
    string P; cin >> P;
    vector<int> pi = failureFunction(P);
    memset(dp, -1, sizeof dp);
    cout << solve(1, 0, P, pi);
}