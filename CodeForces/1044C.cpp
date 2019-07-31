#include <bits/stdc++.h>
using namespace std;
 
const int N = 3e5 + 5;
 
int comp(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
 
	int ans = 0;
	ans += abs(a.first - b.first);
	ans += abs(b.first - c.first);
	ans += abs(c.first - a.first);
 
	ans += abs(a.second - b.second);
	ans += abs(b.second - c.second);
	ans += abs(c.second - a.second);
 
	return ans;
}
 
int main() {
 
	int n, maxx = -1e9, minx = 1e9, miny = 1e9, maxy = -1e9, x, y;
	int ind[4];
	pair<int, int> p[N];
 
	cin >> n;
	for(int i=0; i<n; i++) {
		scanf("%d%d", &x, &y);
		p[i] = make_pair(x, y);
 
		if(x > maxx) {
			ind[0] = i;
			maxx = x;
		}
		if(y > maxy) {
			ind[1] = i;
			maxy = y;
		}
		if(x < minx) {
			ind[2] = i;
			minx = x;
		}
		if(y < miny) {
			ind[3] = i;
			miny = y;
		}
	}
 
	int ans = 0;
	for(int i=0; i<4; i++)
		for(int j=i+1; j<4; j++)
			for(int k=0; k<n; k++)
				if(k != ind[i] && k != ind[j])
					ans = max(ans, comp(p[ind[i]], p[ind[j]], p[k]));
 
	printf("%d ", ans);
	ans = 2*((maxx - minx) + (maxy - miny));
	for(int i=4; i<=n; i++)
		printf("%d ", ans);
	printf("\n");
}