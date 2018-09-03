#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3)
#define readll(num) scanf("%lld", &num)
#define read3ll(num1, num2, num3) scanf("%lld%lld%lld", &num1, &num2, &num3)
#define reads(str) scanf("%s", str)
#define readc(ch) scanf("%c", &ch)

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

int n, a, b, cur=1;
int s[200009];
set<int> v[200009];

bool BFS() {

	bool vis[200009];
	memset(vis, 0, sizeof(vis));
	queue<int> q;

	q.push(1);
	vis[1] = 1;
	if(s[0] !=  1)
		return 0;

	while(!q.empty()) {

		int p = q.front();
		q.pop();

		for(int i=0; i<v[p].size() -1; i++) {

			if(v[p].find(s[cur]) == v[p].end()) {
				//printf(">> %d %d\n", p, s[cur]);
				return 0;
			}

			if(vis[s[cur]])
				return 0;

			q.push(s[cur]);
			vis[s[cur]] = 1;
			cur++;

			if(cur == n)
				return 1;
		}
	}

	return 1;
}

int main() {

	read(n);
	v[1].insert(0);
	for(int i=0; i<n-1; i++) {
		read(a);
		read(b);
		v[a].insert(b);
		v[b].insert(a);
	}

	for(int i=0; i<n; i++)
		read(s[i]);

	printf("%s\n", BFS() ? "Yes":"No");
}

/*

7
1 2
1 3
2 4
2 5
3 6
3 7
1 2 3 5 7 4 6


*/