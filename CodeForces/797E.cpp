#include <bits/stdc++.h>
using namespace std;

#define f(i, num) for(int i=0; i<num; i++) //0 - based indexing
#define f1(i, num) for(int i=1; i<=num; i++) //1 - based indexing
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define read(num) scanf("%d", &num)
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

int main()
{
	int n, k, q, p, siz, ans;
	int a[100009], precomp[100009][109];

	read(n);
	f1(i, n)
		read(a[i]);

	siz = sqrt(n)/3;
	//Precomputation
	F(i, 1, siz+1, 1)
		F_(j, n, 0, 1)
		{
			if(j+a[j]+i > n)
				precomp[j][i] = 1;
			else
				precomp[j][i] = precomp[j+a[j]+i][i] +1;
		}

	read(q);
	f(z, q)
	{
		read2(p, k);
		if(k>siz)
		{
			ans = 0;
			while(p<=n)
			{
				ans++;
				p = p+a[p]+k;
			}
			printf("%d\n", ans);
		}
		else
		{
			printf("%d\n", precomp[p][k]);
		}
	}
}