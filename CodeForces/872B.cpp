#include <bits/stdc++.h>
//#include <unordered_map>
 
#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)
 
#define read(num) scanf("%d", &num)
#define read2(numa, num2) scanf("%d%d", &numa, &num2)
#define read3(numa, num2, num3) scanf("%d%d%d", &numa, &num2, &num3)
#define reads(str) scanf("%s", str)
#define readc(ch) scanf("%c", &ch)
 
#define M 1000000007
#define pb push_back
#define mp make_pair
 
#define pii pair<int, int>
#define vi vector<int>
#define ll long long
 
using namespace std;

int main()
{
	int n, k, a[100009], b[100009], c[100009];

	read2(n, k);
	f(i, n)
		read(a[i]);

	int mini = 2e9;
	if(k==1)
	{
		f(i, n)
			mini = min(mini, a[i]);

		printf("%d\n", mini);
		return 0;
	}
	else if(k==2)
	{
		b[0] = a[0];
		F(i, 1, n, 1)
			b[i] = min(b[i-1], a[i]);

		c[n-1] = a[n-1];
		F_(i, n-2, -1, 1)
			c[i] = min(c[i+1], a[i]);

		int ans = -2e9;
		f(i, n-1)
		{
			//printf("--%d %d--\n", b[i], c[i+1]);
			ans = max(ans, max(b[i], c[i+1]));
		}

		printf("%d\n", ans);
		return 0;
	}
	else
	{
		int ans = -2e9;
		f(i, n)
			ans = max(ans, a[i]);

		printf("%d\n", ans);
		return 0;
	}
}