#include <iostream>
#include <queue>
using namespace std;

struct info{
	int y,x;
	int priority;
	
	bool const operator < (const info& b) const{
		if(priority == b.priority){
			if(y == b.y) return x > b.x;
			return y > b.y;
		}
		return priority > b.priority;
	}
};

int w,h;

string map[1000];

bool visit[1000][1000];

int dy[] = {-1,0,1,0}, dx[] = {0,-1,0,1};

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>w>>h;
	
	priority_queue<info> q;
	
	for(int i =0; i<w; i++){
		cin>>map[i];
		if(!q.size()){
			for(int j =0; j<h; j++)
				if(map[i][j] == 'S'){
					q.push({i,j,0});
					visit[i][j]= true;
				}
		}
	}
	
	int ans = 0;
	
	while(q.size()){
		info t = q.top(); q.pop();
		int y = t.y,
				x = t.x;
		//cout<<y<<" "<<x<<" "<<ans<<"\n";
		if(map[y][x] == 'E'){ break;
		}else if(map[y][x] == 'P'){
			for(int i = -1; i<2; i++) for(int j = -1; j<2; j++){
				int ny = y + i,
						nx = x + j;
				if(ny <0 || ny>= w || nx <0 || nx>=h) continue;
				if(map[ny][nx] == 'P') ans++;
			}
			ans -= 4;
		}else if(map[y][x] == '0'){
			for(int i = -1; i<2; i++) for(int j = -1; j<2; j++){
				int ny = y + i,
						nx = x + j;
				if(ny <0 || ny>= w || nx <0 || nx>=h) continue;
				if(map[ny][nx] == 'P') ans++;
			}
		}
		
		for(int dir =0; dir<4; dir++){
			int ny = y + dy[dir],
					nx = x + dx[dir];
			
			if(ny <0 || ny>= w || nx <0 || nx>=h) continue;
			if(visit[ny][nx]) continue;
			
			int priority;
			if(map[ny][nx] == 'E') priority = 0;
			else if(map[ny][nx] == 'P') priority = 1;
			else priority = 2;
			
			visit[ny][nx] = true;
			q.push({ny,nx,priority});
		}
	}
	if(ans <0) ans = 0;
	cout<<ans;
}