#include <iostream>
#include <vector>

#define f first
#define t second

using namespace std;

typedef pair<int,int> Edge;

int v,e;
vector<int> con[10001];

int order = 0;
int pk[10001];
int bccCnt[10001];

int tarjan(int tNode, int prev, vector<Edge>& stack){
    int p = pk[tNode] = ++order;

    for(int& nNode: con[tNode]){
        if(prev == nNode) continue;

        if(!pk[nNode]){
            Edge tEdge = Edge(tNode, nNode);
            stack.push_back({tNode, nNode});

            int childP = tarjan(nNode, tNode, stack);
            p = min(p , childP);

            if(pk[tNode] <= childP){
                
                for(int i = stack.size() - 1; i>=0; --i){
                    Edge t = stack.back();
                    stack.pop_back();

                    ++bccCnt[t.t];
                    if(t == tEdge){
                        ++bccCnt[t.f];
                        break;
                    }
                }
            }
        }else p = min(p, pk[nNode]);
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

    vector<Edge> stack;
    for(int i = 1; i<=v; ++i)
        if(!pk[i]) tarjan(i, -1, stack);

    vector<int> ac;

    for(int i = 1; i<=v; ++i)
        if(bccCnt[i] >= 2) ac.push_back(i);
    
    cout<<ac.size()<<"\n";
    for(auto& node: ac)cout<<node<<" ";
}