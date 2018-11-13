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

int main() {

	int n, m, t, q;
	pii p[100009];
	int a[100009], b[100009];

	read(t);
	while(t--) {

		read(n);
		read(m);

		for(int i=0; i<n; i++) {
			read(p[i].first);
			read(p[i].second);
		}

		p[n] = mp(2e9+5, 2e9+5);

		sort(p, p+n+1);
		for(int i=0; i<=n; i++) {
			a[i] = p[i].first;
			b[i] = p[i].second;
		}

		while(m--) {
			read(q);
			int t1 = lower_bound(a, a+n+1, q) - a;

			if(t1 == 0) {
				if(a[t1] - q > 1e9)
					printf("-1\n");
				else
					printf("%d\n", a[t1] - q);
				continue;
			}

			if(b[t1 -1] <= q) {
				if(a[t1] - q > 1e9)
					printf("-1\n");
				else
					printf("%d\n", a[t1] - q);
			}
			else {
				printf("%d\n", 0);
			}
		}
	}
}