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
	int t, n;
	int a[100009], ans[100009];

	read(t);
	f(z, t)
	{
		read(n);
		f(i, n)
			read(a[i]);

		memset(ans, 0, sizeof(ans));
		f(i, n)
		{
			int t1 = 0;
			F(j, i+1, n, 1)
			{
				if(a[i] >= t1)
					ans[j]++;
				else
					break;

				t1 += a[j];
			}

			t1 = 0;
			F_(j, i-1, -1, 1)
			{
				if(a[i] >= t1)
					ans[j]++;
				else
					break;

				t1 += a[j];
			}
		}

		f(i, n)
			printf("%d ", ans[i]);

		printf("\n");
	}
}