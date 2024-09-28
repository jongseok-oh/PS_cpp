#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

ll solve(vector<int>& students) {
    int n = students.size();
    if (n < 3) return 0;
    vector<int> sumCnt(40001);

    ll ret = 0;
    for (int i = 0; i < n; ++i) {
        int tnum = students[i];
        ret += sumCnt[30000 - tnum];

        for (int j = 0; j < i; ++j) {
            ++sumCnt[students[j] + tnum];
        }
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> students(n);
    for (auto& student : students) {
        cin >> student;
        student += 10000;
    }
    cout << solve(students);
}