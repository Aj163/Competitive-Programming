#include <bits/stdc++.h>
using namespace std;
 
const int N = 4e5 + 5;
 
int main() {
 
	int n, siz;
	int a[N];
	map<int, int> m;
 
	cin >> n >> siz;
 
	siz *= 8;
	for(int i=0; i<n; i++) {
		scanf("%d", &a[i]);
		m[a[i]]++;
	}
 
	int req = min(30, siz / n);
	req = (1<<req);
 
	auto p = m.begin();
	int ans = n;
	int cost = n, curr = 0;
 
	for(auto start = m.begin(); start != m.end(); start++) {
		while(p != m.end() && curr < req) {
			cost -= p->second;
			curr++;
			p++;
		}
		// printf(">> %d\n", cost);
		ans = min(ans, cost);
 
		cost += start->second;
		curr--;
	}
 
	printf("%d\n", ans);
}