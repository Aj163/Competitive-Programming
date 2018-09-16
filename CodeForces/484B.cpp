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

	int n, temp;
	set<int> s;
	int a[200009], near[2000009];

	read(n);
	for(int i=0; i<n; i++) {
		read(temp);
		s.insert(temp);
	}

	n=0;
	for(auto it : s)
		a[n++] = it;

	int it = n-1;
	for(int i=2000008; i>=0; i--) {
		while(it >=0 && a[it] >= i)
			it--;

		if(it == -1)
			break;

		near[i] = a[it];
	}

	int ans = 0;
	for(int j=0; j<n; j++)
		for(int i=2*a[j]; i<=2000000; i+=a[j])
			ans = max(ans, near[i] % a[j]);

	printf("%d\n", ans);
}