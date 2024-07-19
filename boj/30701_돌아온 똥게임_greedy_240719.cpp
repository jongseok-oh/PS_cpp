#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ret = 0;
long long D;
vector<int> monsters, equipments;

void addMonster(int monster) {
    D += monster;
    ++ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N>>D;
    int a, x;
    for (int i = 0; i < N; ++i) {
        cin >> a >> x;
        if (a == 1) monsters.push_back(x);
        else equipments.push_back(x);
    }
    sort(monsters.begin(), monsters.end());
    sort(equipments.begin(), equipments.end());

    int j = 0, m = m = equipments.size();
    for (int i = 0, n = monsters.size(); i < n; ++i) {
        int monster = monsters[i];
        if (D > monster) {
            addMonster(monster);
        }else {
            while (j < m && D <= monster) {
                D *= equipments[j++];
                ++ret;
            }
            if (D > monster) addMonster(monster);
        }
    }

    ret += m-j;
    cout << ret;
}