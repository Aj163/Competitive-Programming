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

	int t, n, k;
	int a[5009];

	read(t);
	for(int z=1; z<=t; z++) {
		cin >> n >> k;
		for(int i=0; i<n; i++)
			read(a[i]);

		sort(a, a+n);

		int curr=0, day=0, ans=0;
		for(int i=0; i<n; i++) {
			if(day < a[i]) {
				curr++;
				ans++;
			}
			else
				continue;

			if(curr == k) {
				day++;
				curr = 0;
			}
		}

		printf("Case #%d: %d\n", z, ans);
	}
}