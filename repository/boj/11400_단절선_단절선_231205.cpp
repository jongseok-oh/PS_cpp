#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define _MAX 100001

using namespace std;

struct Edge{
    int f,t;
    Edge(int f, int t){
        if(f > t) swap(f,t);
        this->f =f;
        this->t = t;
    }
};

int v, e;

vector<int> con[_MAX];

int order = 0;
int pk[_MAX];

int dfs(int tNode, int prev, vector<Edge>& edges){
    int p = pk[tNode] = ++order;

    for(int& nNode: con[tNode]){
        if(nNode == prev) continue;
        
        if(!pk[nNode]){
            int temp = dfs(nNode, tNode, edges);

            p = min(p, temp);

            if(temp > pk[tNode]) edges.push_back(Edge(tNode, nNode));
        }
        else p = min(p, pk[nNode]);
    }
    return p;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>v>>e;
    
    int a,b;
    while(e--){
        cin>>a>>b;
        con[a].push_back(b);
        con[b].push_back(a);
    }

    vector<Edge> edges;
    for(int i =1; i<=v; ++i)
        if(!pk[i]) dfs(i, -1, edges);
    
    sort(edges.begin(), edges.end(), [&](auto& a, auto& b){
        return a.f < b.f || (a.f == b.f && a.t < b.t);
    });
    cout<<edges.size()<<"\n";
    for(auto& edge: edges){
        cout<<edge.f<<" "<<edge.t<<"\n";
    }
}