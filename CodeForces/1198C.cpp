#include <bits/stdc++.h>
using namespace std;
 
const int N = 5e5 + 5;
 
int n, m;
int vertices[N];
pair<int, int> edges[N];
bool chosen[N];
 
int main() {
 
	int t;
 
	cin >> t;
	while(t--) {
		scanf("%d%d", &n, &m);
		n *= 3;
 
		// memset(chosen, 0, sizeof(chosen));
		// memset(vertices, 0, sizeof(vertices));
		for(int i=0; i<=max(n, m); i++) {
			chosen[i] = 0;
			vertices[i] = 0;
		}
 
		int matching = 0;
 
		for(int i=1; i<=m; i++) {
			scanf("%d%d", &edges[i].first, &edges[i].second);
			if(vertices[edges[i].first] == 0 && vertices[edges[i].second] == 0) {
				chosen[i] = 1;
				vertices[edges[i].first] = 1;
				vertices[edges[i].second] = 1;
				matching++;
			}
		}
 
		int cnt = 0;
		if(matching >= n / 3) {
			printf("Matching\n");
			for(int i=1; i<=m; i++)
				if(chosen[i] && cnt < n/3) {
					printf("%d ", i);
					cnt++;
				}
		}
		else {
			printf("IndSet\n");
			for(int i=1; i<=n; i++)
				if(vertices[i] == 0 && cnt < n/3) {
					printf("%d ", i);
					cnt++;
				}
		}
 
		printf("\n");
	}
}