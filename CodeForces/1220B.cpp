#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

int main() {

	int a[N][N];
	int n;

	cin >> n;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			scanf("%d", &a[i][j]);

	int num = 0;
	for(int i=1; i<n; i++)
		num = __gcd(num, a[0][i]);

	int a1 = num;
	// printf(">> %d\n", num);
	for(int i=1; i*1ll*i<=num; i++) {
		if(num % i == 0) {
			// printf(">>> %d\n", i);
			int a2 = a[0][1] / i;
			int a3 = a[0][2] / i;
			if(a2*1ll*a3 == a[1][2]) {
				a1 = i;
				break;
			}

			a2 = a[0][1] / (num / i);
			a3 = a[0][2] / (num / i);
			if(a2*1ll*a3 == a[1][2]) {
				a1 = num / i;
				break;
			}
		}
	}

	printf("%d ", a1);
	for(int i=1; i<n; i++)
		printf("%d ", a[0][i] / a1);
	printf("\n");
}