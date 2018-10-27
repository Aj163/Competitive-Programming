#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
#define readll(num) scanf("%lld", &num)
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

int mul(int a[2][2], int b[2][2])
{
	int c[2][2] = {0};
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			for(int k=0; k<2; k++)
				c[i][j] = (c[i][j] + a[i][k]*1ll*b[k][j])%M;

	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			a[i][j] = c[i][j];
}

int power(int a[2][2], int n)
{
	int t[2][2] = {a[0][0], a[0][1], a[1][0], a[1][1]};
	a[0][0] = a[1][1] = 1;
	a[0][1] = a[1][0] = 0;
	while(n)
	{
		if(n%2)
			mul(a, t);
		n/=2;
		mul(t, t);
	}
}

int fib(int a, int b, int n)
{
	if(n==1)
		return a;
	if(n==2)
		return b;

	int mat[2][2] = {0, 1, 1, 1};
	power(mat, n-2);
	return (mat[1][0]*1ll*a + mat[1][1]*1ll*b)%M;
}

int main()
{
	int t, m, n, a;
	int ans;

	read(t);
	while(t--)
	{
		ans = 0;
		read2(m, n);
		int x = fib(1, 0, n);
		for(int i=0; i<m; i++)
		{
			read(a);
			ans = (ans + ((x*1ll*m)%M)*1ll*a)%M;
		}

		int y = fib(0, 1, n);
		for(int i=0; i<m; i++)
		{
			read(a);
			ans = (ans + ((y*1ll*m)%M)*1ll*a)%M;
		}

		printf("%d\n", ans);
	}
}