#include <bits/stdc++.h>
using namespace std;
 
const int N = 205;
vector<int> ans[N];
vector<int> v[N];
int vis[N];
int ptr = 0;
 
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
 
 
void dfs(int x) {
 
    if(vis[x])
        return;
    vis[x] = 1;
    ans[ptr].push_back(x);
 
    for(auto it : v[x])
        dfs(it);
}
 
bool prime(int a) {
 
    for(int i=2; i*i <= a; i++)
        if(a % i == 0)
            return 0;
 
    return 1;
}
 
int main() {
 
    int s = 201, t = 202;
	Dinic d(N, s, t);
    int cnt[2] = {0, 0};
 
    int n;
    int a[N];
 
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
 
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++)
            if(a[i]%2 == 1 && a[j]%2 == 0 && prime(a[i] + a[j]))
                d.add_edge(i, j, 1);
 
        if(a[i] % 2 == 1) 
            d.add_edge(s, i, 2);
        else
            d.add_edge(i, t, 2);
        cnt[a[i] % 2]++;
    }
 
    if(cnt[0] != cnt[1] || d.flow() != 2*cnt[0]) {
        printf("Impossible\n");
        return 0;
    }
 
    for(auto it : d.edges)
        if(it.flow > 0) {
            if(it.v == s || it.u == t)
                continue;
 
            // printf(">> %d %d\n", it.u, it.v);
            v[it.u].push_back(it.v);
            v[it.v].push_back(it.u);
        }
 
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<n; i++)
        if(!vis[i]) {
            dfs(i);
            ptr++;
        }
 
    printf("%d\n", ptr);
    for(int i=0; i<ptr; i++) {
        printf("%d ", (int)ans[i].size());
        for(auto it : ans[i])
            printf("%d ", it + 1);
 
        printf("\n");
    }
}