#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int main() {

	int t, n, g, m;
	int a[N];
	char s[N][5];

	cin >> t;
	for(int z=1; z<=t; z++) {
		scanf("%d%d%d", &n, &g, &m);

		vector<int> finish_c[N], finish_a[N];
		vector<pair<int, pair<int, int> > > ans[N];
		int cnt_c[N], cnt_a[N];

		memset(cnt_a, 0, sizeof(cnt_a));
		memset(cnt_c, 0, sizeof(cnt_c));

		bool cl = 0, acl = 0;

		for(int i=0; i<g; i++) {
			scanf("%d", &a[i]);
			a[i]--;
			scanf("%s", s[i]);

			if(s[i][0] == 'C') {
				finish_c[(a[i] + m) % n].push_back(i);
				cl = 1;
			}
			else if(s[i][0] == 'A'){
				int temp = (a[i] - m) % n;
				temp += n;
				temp %= n;
				finish_a[temp].push_back(i);
				acl = 1;
			}
		}

		// printf("------------- FINISH C\n");
		// for(int i=0; i<n; i++) {
		// 	for(auto it : finish_c[i])
		// 		printf("%d : %d\n", i, it);
		// }
		// printf("-------------\n");

		int start = -1, pos = n-1, prev = -1, tim = m;

		// Clockwise
		while(start != pos && cl) {
			if(finish_c[pos].size() && start == -1)
				start = pos;

			if(start == -1) {
				pos = (pos -1 + n) % n;
				continue;
			}

			if(finish_c[pos].size()) {
				prev = pos;
				tim = m;
			}

			if(tim >= 0)
				ans[pos].push_back(make_pair(tim, make_pair(prev, 0)));

			pos = (pos -1 + n) % n;
			tim--;
		}

		// printf("-------------\n");
		// for(int i=0; i<n; i++) {
		// 	for(auto it : ans[i])
		// 		printf("%d : %d, %d\n", i, it.first, it.second.second);
		// }
		// printf("-------------\n");

		// Anit-Clockwise
		start = -1;
		pos = 0;
		tim = m;
		prev = -1;
		while(start != pos && acl) {
			if(finish_a[pos].size() && start == -1)
				start = pos;

			if(start == -1) {
				pos = (pos +1) % n;
				continue;
			}

			if(finish_a[pos].size()) {
				prev = pos;
				tim = m;
			}

			if(tim >= 0) {
				if(ans[pos].size()) {
					if(ans[pos][0].first < tim)
						ans[pos][0] = make_pair(tim, make_pair(prev, 1));
					else if(ans[pos][0].first == tim)
						ans[pos].push_back(make_pair(tim, make_pair(prev, 1)));
				}
				else
					ans[pos].push_back(make_pair(tim, make_pair(prev, 1)));
			}

			pos = (pos +1) % n;
			tim--;
		}

		for(int i=0; i<n; i++) {
			for(auto it : ans[i]) {
				if(it.second.second == 0)
					cnt_c[it.second.first]++;
				else
					cnt_a[it.second.first]++;
			}
		}

		int answer[N];
		memset(answer, 0, sizeof(answer));
		for(int i=0; i<n; i++) {
			for(auto it : finish_c[i]) {
				answer[it] += cnt_c[i];
			}

			for(auto it : finish_a[i]) {
				answer[it] += cnt_a[i];
			}
		}

		printf("Case #%d: ", z);
		for(int i=0; i<g; i++)
			printf("%d ", answer[i]);

		printf("\n");
	}
}

/*

1
5 3 2
5 C
2 A
1 A


*/