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

	int n;
	int a[2009];

	read(n);
	for(int i=0; i<n; i++) {
		read(a[i]);
		a[i] = abs(a[i]);
	}

	int p, q;
	ll ans=0;
	for(int i=0; i<n; i++) {
		p = q = 0;
		for(int j=0; j<n; j++)
			if(a[i] > a[j]) {
				if(i > j)
					p++;
				else if(i < j)
					q++;
			}

		ans += min(p, q);
	}

	printf("%lld\n", ans);
}