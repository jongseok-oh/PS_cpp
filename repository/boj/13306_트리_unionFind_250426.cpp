#include <vector>
#include <iostream>

using namespace std;

struct Query{
    int x, b, c, d;
};

int find(int node, vector<int>& group){
    if(group[node] == -1) return node;
    return group[node] = find(group[node], group);
}

void _union(int a, int b, vector<int>& group){
    int aP = find(a, group), bP = find(b, group);

    if(aP == bP) return;
    group[aP] = bP;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, q;
    cin >> n >> q;

    vector<int> parent(n + 1);
    for(int i = 0; i<n-1; ++i){
        int p; cin>>p;
        parent[i + 2] = p;
    }

    vector<Query> queries(n - 1 + q);
    for(auto& [x, b, c, d] : queries){
        cin>>x;
        if(x == 0){
            cin>>b;
        }else{
            cin>>c>>d;
        }
    }

    vector<int> group(n + 1, -1);
    vector<bool> result;
    for(int i = n - 2 + q; i>=0; --i){
        auto& q = queries[i];
        if(q.x == 0){
            _union(parent[q.b], q.b, group);
        }else{
            int cP = find(q.c, group), dP = find(q.d, group);
            result.push_back(cP == dP);
        }
    }

    for(int i = q-1; i>=0; --i){
        cout<<(result[i]?"YES":"NO")<<"\n";
    }
}