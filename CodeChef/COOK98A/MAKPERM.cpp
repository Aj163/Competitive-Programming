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

	int n, t;
	int a;
	set<int> s;

	read(t);
	while(t--) {

		read(n);
		s.clear();
		for(int i=0; i<n; i++) {
			read(a);
			if(a<=n)
				s.insert(a);
		}

		printf("%d\n", n - s.size());
	}
}