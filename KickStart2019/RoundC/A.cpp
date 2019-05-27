#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

const int N = 5e4 + 5;

int t, l, r, c, x, y;
map<pii, pii > n, e, w, s;
map<pii, int> vis;
char S[N];

pii next(pii q, char dir) {

	if(dir == 'N') {
		pii prev = q, temp, future = q;

		if(n.find(future) == n.end())  {
			future.first--;
			n[prev] = future;
		}
		else
			future = n[future];
		
		while(vis[future]) {
			pii temp;
			if(n.find(future) != n.end())
			 	temp = n[future];
			else {
				temp = future;
				temp.first--;
			}

			n[prev] = temp;
			prev = future;
			future = temp;
		}

		vis[future] = 1;
		return future;
	}


	if(dir == 'S') {
		pii prev = q, temp, future = q;

		if(s.find(future) == s.end())  {
			future.first++;
			s[prev] = future;
		}
		else
			future = s[future];
		
		while(vis[future]) {
			pii temp;
			if(s.find(future) != s.end())
			 	temp = s[future];
			else {
				temp = future;
				temp.first++;
			}

			s[prev] = temp;
			prev = future;
			future = temp;
		}

		vis[future] = 1;
		return future;
	}


	if(dir == 'E') {
		pii prev = q, temp, future = q;

		if(e.find(future) == e.end())  {
			future.second++;
			e[prev] = future;
		}
		else
			future = e[future];
		
		while(vis[future]) {
			pii temp;
			if(e.find(future) != e.end())
			 	temp = e[future];
			else {
				temp = future;
				temp.second++;
			}

			e[prev] = temp;
			prev = future;
			future = temp;
		}

		vis[future] = 1;
		return future;
	}


	if(dir == 'W') {
		pii prev = q, temp, future = q;

		if(w.find(future) == w.end())  {
			future.second--;
			w[prev] = future;
		}
		else
			future = w[future];
		
		while(vis[future]) {
			pii temp;
			if(w.find(future) != w.end())
			 	temp = w[future];
			else {
				temp = future;
				temp.second--;
			}

			w[prev] = temp;
			prev = future;
			future = temp;
		}

		vis[future] = 1;
		return future;
	}
}

int main() {

	cin >> t;
	for(int z=1; z<=t; z++) {
		scanf("%d%d%d%d%d", &l, &r, &c, &x, &y);
		n.clear();
		e.clear();
		w.clear();
		s.clear();
		vis.clear();

		vis[make_pair(x, y)] = 1;

		scanf("%s", S);

		for(int i=0; i<l; i++) {
			pii temp = next(make_pair(x, y), S[i]);
			x = temp.first;
			y = temp.second;

			// printf("Case #%d: %d %d\n", z, x, y);
		}

		printf("Case #%d: %d %d\n", z, x, y);
	}
}