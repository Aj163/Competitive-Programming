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

	int n, s;
	int a[200009];

	read(n);
	read(s);
	for(int i=0; i<n; i++)
		read(a[i]);

	sort(a, a+n);
	ll ans=0, sum=0;

	if(a[n/2] > s) {
		for(int i=n/2; i>=0; i--) 
			ans += max(a[i] - s, 0); 
	}
	else {
		for(int i=n/2; i<n; i++)
			ans += max(s - a[i], 0);
	}

	printf("%lld\n", ans);
}