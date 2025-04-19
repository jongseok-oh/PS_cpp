#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N,K,D;

struct Student{
	int d;
	vector<int> algo;
}students[100000];

int cnt[30];

int calcUnion(){
	int ret = 0;
	for(int i = 0; i<K; ++i)
		if(cnt[i]) ++ret;
	return ret;
}

int calcIntersection(int len){
	int ret = 0;
	for(int i = 0; i<K; ++i)
		if(cnt[i] == len) ++ret;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin>>N>>K>>D;

	int m, d, a;
	for(int i = 0; i<N; ++i){
		cin>>m>>d; students[i].d = d;
		for(int j = 0; j<m; j++){
			cin>>a; 
			students[i].algo.push_back(--a);
		}
	}

	sort(students, students + N, [&](auto& a, auto& b){
		return a.d < b.d;
	});

	int ret = 0;
	for(int i = 0, j =0; i<N && j<N; ++i){
		while (j<N && students[j].d - students[i].d <= D)
		{
			for(int tAlgo: students[j].algo) ++cnt[tAlgo];
			++j;
		}
		int len = j - i;
		ret = max(ret, (calcUnion() - calcIntersection(len)) * len);
		for(int tAlgo: students[i].algo) --cnt[tAlgo];
	}
	cout<<ret;
}