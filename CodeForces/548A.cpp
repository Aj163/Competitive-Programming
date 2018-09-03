#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
#define readll(num) scanf("%lld", &num)
#define read3ll(num1, num2, num3) scanf("%lld%lld%lld", &num1, &num2, &num3)
#define read2(num1, num2) scanf("%d%d", &num1, &num2)
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3)
#define reads(str) scanf("%s", str)
#define readc(ch) scanf("%c", &ch)

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

void chk(char s[], int a, int b) {
	while(a<=b) {
		if(s[a] != s[b]) {
			//printf("%d %d\n", a, b);
			printf("NO\n");
			exit(0);
		}
		else
			a++, b--;
	}
}

int main() {

	char s[1009];
	int k, n;

	reads(s);
	n = strlen(s);
	read(k);

	if(n%k != 0) {
		printf("NO\n");
		return 0;
	}

	for(int i=0; i<n; i+=n/k)
		chk(s, i, i+n/k-1);

	printf("YES\n");
}