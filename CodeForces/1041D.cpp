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

#define maxn 200009

int main() {

	ll n, h;
	pair<ll, ll> p[maxn];

	cin >> n >> h;
	for(int i=0; i<n; i++) {
		readll(p[i].first);
		readll(p[i].second);
	}

	sort(p, p+n);
	p[n] = mp(1e11, 1e12);

	ll sums[maxn];
	pair<ll, ll> points[maxn];

	for(int i=0; i<n; i++) {
		points[i] = mp(p[i].second, p[i+1].first - p[i].second);
		if(i==0)
			sums[i] = points[i].second;
		else
			sums[i] = sums[i-1] + points[i].second;
	}

	

	ll SUMS[maxn];
	SUMS[0] = 0;
	for(int i=0; i<=n; i++)
		SUMS[i] = SUMS[i-1] + p[i].second - p[i].first;
	ll ANS = h;

	for(int i=0; i<n; i++) {
		ll sub=0;
		if(i>0)
			sub = sums[i-1];

		int l=i, hh=n-1, mid, ans=i;
		while(l<=hh) {
			mid = (l+hh)/2;
			if(sums[mid] - sub >= h) {
				ans = mid;
				hh = mid -1;
			}
			else
				l = mid +1;
		}

		

		int SUB = 0;
		if(i>0)
			SUB = SUMS[i-1];
		ANS = max(ANS, SUMS[ans] - SUB + h);
		//printf(">> %d %lld\n", ans, SUMS[ans] - SUB + h);
	}

	printf("%lld\n", ANS);
}