#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

using ll = long long;

ll solve(vector<int>& students) {
    int n = students.size();
    if (n < 3) return 0;
    unordered_map<int, int> numCnt, sumCnt;

    ll ret = 0;
    for (int i = 0; i < n; ++i) {
        int tnum = students[i];
        if (sumCnt.count(-tnum)) {
            ret += sumCnt[-tnum];
        }
        
        for (const auto& [num, cnt] : numCnt) {
            sumCnt[num + tnum] += cnt;
        }

        ++numCnt[tnum];
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> students(n);
    for (auto& student : students) {
        cin >> student;
    }
    cout << solve(students);
}