#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

typedef long long ll;

using namespace std;

int n;

struct Rect {
    int x1, x2, y1, y2;
}rects[5001];

vector<int> con[5001];

void makeGraph() {
    for (int i = 1; i <= n; ++i) for (int j = i + 1; j <= n; ++j) {

        Rect r1 = rects[i], r2 = rects[j];
        if (r1.x1 > r2.x1) swap(r1, r2);
        if (r1.x2 > r2.x1 && (r1.y1 == r2.y2 || r1.y2 == r2.y1)) // 가로 변 맞댄 경우
        {
            con[i].push_back(j);
            con[j].push_back(i);
            continue;
        }

        if (r1.y1 > r2.y1) swap(r1, r2);
        if (r1.y2 > r2.y1 && (r1.x1 == r2.x2 || r1.x2 == r2.x1)) // 세로 변 맞댄 경우
        {
            con[i].push_back(j);
            con[j].push_back(i);
        }
    }
}

ll calcArea(int tNode) {
    return ((ll)rects[tNode].x2 - rects[tNode].x1) * ((ll)rects[tNode].y2 - rects[tNode].y1);
}

bool visit[5001];
// 슈퍼 목장의 불량도 반환
ll bfs(int tNode) {
    queue<int> q;
    q.push(tNode);
    visit[tNode] = true;
    ll sum = calcArea(tNode);

    int minX = rects[tNode].x1, maxX = rects[tNode].x2;
    int minY = rects[tNode].y1, maxY = rects[tNode].y2;
    while (q.size()) {
        int node = q.front(); q.pop();

        for (int& nNode : con[node]) {
            if (!visit[nNode]) {
                q.push(nNode);
                visit[nNode] = true;
                sum += calcArea(nNode);

                minX = min(minX, rects[nNode].x1);
                maxX = max(maxX, rects[nNode].x2);
                minY = min(minY, rects[nNode].y1);
                maxY = max(maxY, rects[nNode].y2);
            }
        }
    }

    return  ((ll)maxX - minX) * ((ll)maxY - minY) - sum;
}

int order = 0;
int pk[5001];
bool curVex[5001];
int dfs(int tNode, int prev, vector<int>& ranches) {
    int p = pk[tNode] = ++order;
    ranches.push_back(tNode);

    int child = 0;
    for (int& nNode : con[tNode]) {
        if (nNode == prev) continue;

        if (!pk[nNode]) {
            int temp = dfs(nNode, tNode, ranches);
            p = min(p, temp);
            ++child;

            if (prev != -1 && temp >= pk[tNode]) curVex[tNode] = true;
        }
        else p = min(p, pk[nNode]);
    }

    // 루트이면서 자식이 둘 이상
    if (prev == -1 && child >= 2)
        curVex[tNode] = true;

    return p;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) 
        cin >> rects[i].x1 >> rects[i].x2 >> rects[i].y1 >> rects[i].y2;
    
    makeGraph();

    ll defect = -1;
    vector<int> startNodes;
    for (int i = 1; i <= n; ++i) {
        if (!visit[i]) {
            ll tDefect = bfs(i);
            if (tDefect > defect) {
                defect = tDefect;
                startNodes = {i};
            }
            else if (tDefect == defect)
                startNodes.push_back(i);
        }
    }

    vector<int> ranches;
    for(int& startNode: startNodes)
        dfs(startNode, -1, ranches);

    sort(ranches.begin(), ranches.end(), [&](int node1,int node2) {
        ll aArea = calcArea(node1);
        ll bArea = calcArea(node2);
        return aArea < bArea || (aArea == bArea && node1 < node2);
    });

    for (auto& idx : ranches) {
        if (!curVex[idx]) {
            cout << idx; return 0;
        }
    }
}