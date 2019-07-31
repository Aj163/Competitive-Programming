#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
 
int n;
int f[N], g[N], color[N];
vector<int> adj[N];
 
long long fastPow(long long a, long long n) {
 
	long long res=1;
	while(n>0) {
		if(n%2)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		n /= 2;
	}
 
	return res;
}
 
void dfs(int v, int p) {
 
	for(int u : adj[v])
		if(u != p)
			dfs(u, v);
 
	if(color[v] == 0) {
		// v is white
		g[v] = 1;
		for(int u : adj[v])
			if(u != p)
				g[v] = (g[v] * 1ll * (f[u] + g[u])) % MOD;
 
		f[v] = 0;
		for(int u : adj[v])
			if(u != p) {
				int temp = (g[v] * 1ll * fastPow((f[u] + g[u]) % MOD, MOD -2)) % MOD;
				f[v] = (f[v] + f[u] * 1ll * temp) % MOD;
			}
	}
	else {
		// v is black
		g[v] = 0;
		f[v] = 1;
		for(int u : adj[v])
			if(u != p)
				f[v] = (f[v] * 1ll * (f[u] + g[u])) % MOD;
	}
}
 
int main() {
 
	int p;
	cin >> n;
	for(int i=0; i<n-1; i++) {
		cin >> p;
		adj[p].push_back(i+1);
		adj[i+1].push_back(p);
	}
 
	for(int i=0; i<n; i++)
		cin >> color[i];
 
	dfs(0, -1);
	printf("%d\n", f[0]);
}