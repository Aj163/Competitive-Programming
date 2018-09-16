#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v[100009];

void BFS() {

	queue<int> q;
	bool vis[100009];

	memset(vis, 0, sizeof(vis));

	q.push(1);
	while(!q.empty()) {
		int p = q.front();
		q.pop();

		if(vis[p])
			continue;
		vis[p] = 1;
		printf("%d ", p);

		for(auto it : v[p])
			q.push(it);
	}
}

int main() {

	int x, y;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> x >> y;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for(int i=1; i<=n; i++)
		sort(v.begin(), v.end());

	BFS();
}