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

	int n, ans=0;
	char a[1000009], b[1000009];

	read(n);
	reads(a);
	reads(b);

	for(int i=0; i<n-1; i++) {
		if(a[i] != b[i] && a[i+1] != b[i+1] && a[i] != a[i+1]) {
			ans++;
			a[i] = b[i];
			a[i+1] = b[i+1];
		}
		else if(a[i] != b[i]) {
			ans++;
			a[i] = b[i];
		}
	}

	if(a[n-1] != b[n-1])
		ans++;

	printf("%d\n", ans);
}