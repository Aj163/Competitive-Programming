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

int f[100009];
int find(int x) {

	if(f[x] == x)
		return x;
	return f[x] = find(f[x]);
}

int main() {

	int n, a, b, arr[100009];
	map<int, int> s;
	int ans[100009], answer[100009];

	read3(n, a, b);
	for(int i=0; i<n; i++) {
		read(arr[i]);
		s[arr[i]] = i;
		f[i] = i;
	}

	memset(ans, 0, sizeof(ans));
	for(int i=0; i<n; i++) {

		if(s.find(a - arr[i]) != s.end()) {
			f[find(s[a - arr[i]])] = find(i);
			ans[i] |= 1;
		}
		if(s.find(b - arr[i]) != s.end()) {
			f[find(s[b - arr[i]])] = find(i);
			ans[i] |= 2;
		}
	}

	for(int i=0; i<n; i++)
		answer[i] = 3;
	for(int i=0; i<n; i++)
		answer[find(i)] &= ans[i];

	for(int i=0; i<n; i++)
		if(answer[i] == 0) {
			printf("NO\n");
			return 0;
		}

	printf("YES\n");
	for(int i=0; i<n; i++)
		printf("%d ", 1- answer[find(i)]%2);
	printf("\n");
}