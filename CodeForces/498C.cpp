#include <bits/stdc++.h>
using namespace std;
 
const int N = 1005, INF = 1e9;
int n, m, x, y;
int a[N], presiz[N];
vector<pair<int, int> > p[N];
 
struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};
 
struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;
 
    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
 
    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }
 
    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }
 
    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
 
    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
 
 
int main() {
 
	cin >> n >> m;
	Dinic d(N, 0, 1);
 
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		int temp = a[i];
		for(int j=2; j*j <= temp; j++) 
			if(temp % j == 0) {
				int cnt = 0;
				while(temp % j == 0) {
					cnt++;
					temp /= j;
				}
 
				p[i].push_back({j, cnt});
			}
 
		if(temp != 1) 
			p[i].push_back({temp, 1});
	}
 
	presiz[1] = 2;
	for(int i=2; i<=n; i++)
		presiz[i] = presiz[i-1] + p[i-1].size();
 
	for(int i=0; i<m; i++) {
		cin >> x >> y;
		for(int j=0; j<p[x].size(); j++)
			for(int k=0; k<p[y].size(); k++)
				if(p[x][j].first == p[y][k].first) {
					int ind1 = presiz[x] + j;
					int ind2 = presiz[y] + k;
 
					if(x % 2)
						swap(ind1, ind2);
					
					// Add egde
					d.add_edge(ind1, ind2, min(p[x][j].second, p[y][k].second));
					// v[ind1].push_back(ind2);
					// v[ind2].push_back(ind1);
					// cap[ind1][ind2] = min(p[x][j].second, p[y][k].second);
				}
	}
 
	// Source, Sink
	for(int i=1; i<=n; i++)
		for(int j=0; j<p[i].size(); j++) {
			int ind = presiz[i] + j;
			if(i%2 == 0) {
				// Source
				d.add_edge(0, ind, p[i][j].second);
				// v[0].push_back(ind);
				// cap[0][ind] = p[i][j].second;
			}
			else {
				// Sink
				d.add_edge(ind, 1, p[i][j].second);
				// v[ind].push_back(1);
				// cap[ind][1] = p[i][j].second;
			}
		}
 
	printf("%lld\n", d.flow());
}