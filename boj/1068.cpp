#include <iostream>
#include <vector>
using namespace std;

int n;

vector<int> edges[50];
int del, root;

// curNode 산하의 LeefNode수 return
// del Node 산하의 수는 세지 않음
int delCntLeefNode(int curNode){
    if(curNode == del) return 0;
    int childs = edges[curNode].size();
    int ret = 0;

    switch (childs)
    {
    case 0: return 1;
    case 1:
        if(edges[curNode][0] == del) return 1;
    default:
        for(int i = 0; i<childs; i++){
            ret += delCntLeefNode(edges[curNode][i]);
        }
    }
    return ret;
}

int main(void)
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (a == -1) { root = i; continue;}
        edges[a].push_back(i);
    }
    cin >> del;
    cout<<delCntLeefNode(root);
}