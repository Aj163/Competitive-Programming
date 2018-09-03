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

#define MAXN 1000009

int main() {

	int n, m, temp, t2;
	vi v[MAXN];

	read(n);
	read(m);

	for(int i=0; i<n; i++) {
		read(temp);
		for(int j=0; j<temp; j++) {
			read(t2);
			v[t2-1].pb(i);
		}
	}

	for(int i=0; i<MAXN; i++)
		sort(v[i].begin(), v[i].end());
	sort(v, v+m);

	int fact[MAXN], ans=1;
	fact[0] = 1;
	for(int i=1; i<MAXN; i++)
		fact[i] = (fact[i-1] * 1ll  * i) % M;

	int cnt=1;
	for(int i=1; i<m; i++) {
		if(v[i] == v[i-1])
			cnt++;
		else {
			ans = (ans * 1ll * fact[cnt]) % M;
			cnt = 1;
		}
	}

	ans = (ans * 1ll * fact[cnt]) % M;
	printf("%d\n", ans);
}