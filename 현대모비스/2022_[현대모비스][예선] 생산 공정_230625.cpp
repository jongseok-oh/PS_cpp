#include <iostream>
#include <vector>

using namespace std;

const int _MAX = 500000 * 10 + 50;
const int ROOT = 1;
int unused = 2;

// 다음 노드, 알파벳
vector<pair<int, char>> Trie[_MAX];

int cnt[_MAX];
pair<string, int> cache[_MAX];

int isIn(int cur, char c){
	for(auto& nNode : Trie[cur]){
		if(nNode.second == c) return nNode.first;
	}
	return -1;
}

void insertTrie(string& s){
	int cur = ROOT;
	
	for(int i = 0; i<s.size(); i++){
		int nNode = isIn(cur, s[i]);
		if(nNode == -1){
			Trie[cur].push_back({unused,s[i]});
			nNode = unused++;
		}
		cur = nNode;
	}
	cnt[cur]++;
}

pair<string, int> initCaching(int node){
	int tCnt = cnt[node]; string temp = "";
	
	for(auto& p: Trie[node]){
		auto tt = initCaching(p.first);
		string tString = p.second + tt.first;
		if(tt.second > tCnt){
			tCnt = tt.second; temp = tString;
		}else if(tt.second == tCnt && temp > tString){
			temp = tString;
		}
	}
	
	return cache[node] = {temp, tCnt};
}

int findFactory(string& str){
	int cur = ROOT;
	for(int i = 0; i<str.size(); i++){
		int nNode = isIn(cur, str[i]);
		if(nNode == -1) return -1;
		cur = nNode;
	}
	return cur;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	while(n--){
		string str; cin>>str;
		insertTrie(str);
	}
	
	initCaching(1);
	
	int k; cin>>k;
	while(k--){
		string str; cin>>str;
		int factory = findFactory(str);
		if(factory == -1 || cache[factory].second == 0) cout<<0;
		else cout<<str+cache[factory].first<<" "<<cache[factory].second;
		cout<<"\n";
	}
}