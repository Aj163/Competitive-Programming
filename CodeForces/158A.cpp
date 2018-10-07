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

	int n, k, ans=0;
	int a[101];

	read(n);
	read(k);
	k--;

	for(int i=0; i<n; i++)
		read(a[i]);

	sort(a, a+n);
	for(int i=0; i<n; i++)
		if(a[i] > 0 && a[i] >= a[n-1-k])
			ans++;

	printf("%d\n", ans);
}