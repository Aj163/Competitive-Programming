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

	int n, t, flag;
	int a[100009];

	read(t);
	while(t--) {
		read(n);
		for(int i=0; i<n; i++)
			read(a[i]);

		if(n%2==1) {
			printf("NO\n");
			continue;
		}
		flag=1;

		for(int i=0; i<n/2; i++) {
			if(a[i] == -1 && a[i+n/2] == -1) {
				a[i] = 1;
				a[i+n/2] = 1;
			}
			else if(a[i] == -1 && a[i+n/2] != -1) {
				a[i] = a[i+n/2];
			}
			else if(a[i] != -1 && a[i+n/2] == -1) {
				a[i+n/2] = a[i];
			}
			else if(a[i] == a[i+n/2]) {
				continue;
			}
			else {
				flag=0;
				break;
			}
		}

		if(flag) {
			printf("YES\n");
			for(int i=0; i<n; i++)
				printf("%d ", a[i]);
			printf("\n");
		}
		else
			printf("NO\n");
	}		
}