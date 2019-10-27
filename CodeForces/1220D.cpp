#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int main() {

	int n;
	long long a[N];

	cin >> n;
	for(int i=0; i<n; i++)
		scanf("%lld", &a[i]);

	int mx = 0, b=0;
	for(int j=0; j<62; j++) {
		int cnt = 0;
		for(int i=0; i<n; i++)
			if(a[i] % (1ll<<j) == 0 && (a[i] / (1ll<<j)) % 2 == 1)
				cnt++;

		if(cnt > mx) {
			mx = cnt;
			b = j;
		}
	}

	printf("%d\n", n - mx);
	for(int i=0; i<n; i++) {
		if(a[i] % (1ll<<b) == 0 && (a[i] / (1ll<<b)) % 2 == 1)
			continue;
		printf("%lld ", a[i]);
	}
	printf("\n");
}