#include <bits/stdc++.h>
using namespace std;
 
map<string, int> m;
map<int, string> inv;
const int N = 1e5 + 5;
 
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
    	// printf("### %d %d %lld\n", v, u, cap);
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
 
	Dinic d(2*N, N-2, N-1);
 
	m["S"] = N+0;		inv[N+0] = "S";
	m["M"] = N+1;		inv[N+1] = "M";
	m["L"] = N+2;		inv[N+2] = "L";
	m["XL"] = N+3;		inv[N+3] = "XL";
	m["XXL"] = N+4;		inv[N+4] = "XXL";
	m["XXXL"] = N+5;	inv[N+5] = "XXXL";
 
	int n, a;
	char s[10];
 
	for(int i=0; i<6; i++) {
		cin >> a;
		d.add_edge(N+i, N-1, a);
	}
 
	cin >> n;
	for(int i=0; i<n; i++) {
		scanf("%s", s);
		int l = strlen(s);
		d.add_edge(N-2, i, 1);
		string temp = "";
		for(int j=0; j<l; j++) {
			if(s[j] == ',') {
				d.add_edge(i, m[temp], 1);
				temp = "";
			}
			else
				temp += s[j];
		}
		d.add_edge(i, m[temp], 1);
	}
 
	if(d.flow() == n) {
		printf("YES\n");
		for(auto it : d.edges)
			if(it.flow > 0 && it.v >= 0 && it.v < N-2)
				cout << inv[it.u] << endl;
	}
	else
		printf("NO\n");
}