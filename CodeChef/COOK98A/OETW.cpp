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

	int n, t, sum;
	int a[2000009];
	set<int> s1, s2;

	read(t);
	while(t--) {
		
		read(n);
		for(int i=0; i<n; i++)
			read(a[i]);

		int ev=0, od=-1, sum=0;
		for(int i=0; i<n; i++) {
			sum += a[i];
			if(sum % 2)
				od = sum;
			else
				ev = sum;
		}

		sum=0;
		for(int i=n-1; i>=0; i--) {
			sum += a[i];
			if(sum % 2)
				od = max(od, sum);
			else
				ev = max(ev, sum);
		}

		int ans = ev/2;
		if(od != -1)
			ans += (od+1)/2;

		printf("%d\n", ans);
	}
}