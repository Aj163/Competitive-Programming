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

	int cnt[100009];
	int n, a;

	memset(cnt, 0, sizeof(cnt));
	read(n);
	for(int i=0; i<n; i++) {
		read(a);

		for(int j=2; j*j<=a; j++)
			if(a%j == 0) {
				cnt[j]++;
				while(a%j == 0)
					a/=j;
			}

		if(a != 1)
			cnt[a]++;
	}

	int ans = 1;
	for(int i=0; i<100009; i++)
		ans = max(ans, cnt[i]);

	printf("%d\n", ans);
}