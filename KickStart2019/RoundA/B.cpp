#include <bits/stdc++.h>
using namespace std;

const int N = 260;

int t, r, c, ans;
char a[N][N];
int dis[N][N], temp[N][N];

int BFS() {

	queue<pair<int, int> >q;

	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++) {
			if(a[i][j] == '1') {
				dis[i][j] = 0;
				q.push(make_pair(i, j));
			}
			else
				dis[i][j] = 1e9;
		}

	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if(x < r-1 && dis[x+1][y] > dis[x][y] +1){
			dis[x+1][y] = dis[x][y] +1;
			q.push(make_pair(x+1, y));
		}
		if(x >0 && dis[x-1][y] > dis[x][y] +1){
			dis[x-1][y] = dis[x][y] +1;
			q.push(make_pair(x-1, y));
		}
		if(y < c-1 && dis[x][y+1] > dis[x][y] +1){
			dis[x][y+1] = dis[x][y] +1;
			q.push(make_pair(x, y+1));
		}
		if(y > 0 && dis[x][y-1] > dis[x][y] +1){
			dis[x][y-1] = dis[x][y] +1;
			q.push(make_pair(x, y-1));
		}
	}

	int mx = -1;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			mx = max(mx, dis[i][j]);

	return mx;

}

int TRY(int a, int b) {

	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			temp[i][j] = dis[i][j];

	queue<pair<int, int> >q;
	temp[a][b] = 0;
	q.push(make_pair(a, b));

	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if(x < r-1 && temp[x+1][y] > temp[x][y] +1){
			temp[x+1][y] = temp[x][y] +1;
			q.push(make_pair(x+1, y));
		}
		if(x >0 && temp[x-1][y] > temp[x][y] +1){
			temp[x-1][y] = temp[x][y] +1;
			q.push(make_pair(x-1, y));
		}
		if(y < c-1 && temp[x][y+1] > temp[x][y] +1){
			temp[x][y+1] = temp[x][y] +1;
			q.push(make_pair(x, y+1));
		}
		if(y > 0 && temp[x][y-1] > temp[x][y] +1){
			temp[x][y-1] = temp[x][y] +1;
			q.push(make_pair(x, y-1));
		}
	}

	int mx = -1;
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			mx = max(mx, temp[i][j]);

	return mx;
}

int main() {
	
	cin >> t;
	for(int z=1; z<=t; z++) {
		cin >> r >> c;
		for(int i=0; i<r; i++)
			cin >> a[i];

		ans = BFS();

		int x, y, mx=-1;
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++) {
				if(mx < dis[i][j]) {
					mx = dis[i][j];
					x = i;
					y = j;
				}
			}

		int test, tt = TRY(x, y);
		int vis[N][N];
		memset(vis, 0, sizeof(vis));
		multiset<pair<int, pair<int, int> > >q;
		q.insert(make_pair(tt, make_pair(x, y)));
		while(!q.empty()) {
			x = (q.begin())->second.first;
			y = (q.begin())->second.second;
			tt = (q.begin())->first;
			ans = min(ans, tt);
			q.erase(q.begin());

			if(vis[x][y])
				continue;
			vis[x][y] = 1;

			// printf("%d %d : %d\n", x, y, tt);

			if(x < r-1 && (test = TRY(x+1, y)) <= tt) {
				q.insert(make_pair(test, make_pair(x+1, y)));
			}
			if(x > 0 && (test = TRY(x-1, y)) <= tt) {
				q.insert(make_pair(test, make_pair(x-1, y)));
			}
			if(y < c-1 && (test = TRY(x, y+1)) <= tt) {
				q.insert(make_pair(test, make_pair(x, y+1)));
			}
			if(y > 0 && (test = TRY(x, y-1)) <= tt) {
				q.insert(make_pair(test, make_pair(x, y-1)));
			}
		}

		// printf(">> %d\n", TRY(4, 1));

		printf("Case #%d: %d\n", z, ans);
	}
}