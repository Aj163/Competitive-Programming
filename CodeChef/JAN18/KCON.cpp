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
#define INF ((int)2e9)
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

int main()
{
	int t, n, k;
	int a[100009];
	ll left, right, mid, ans, sum, full;

	read(t);
	f(z, t)
	{
		read2(n, k);
		f(i, n)
			read(a[i]);

		left = a[0];
		sum = a[0];
		F(i, 1, n, 1)
		{
			sum += a[i];
			left = max(left, sum);
		}

		right = a[n-1];
		sum = a[n-1];
		F_(i, n-2, -1, 1)
		{
			sum += a[i];
			right = max(right, sum);
		}

		mid = a[0];
		sum = a[0];
		full = a[0];
		F(i, 1, n, 1)
		{
			full += a[i];
			sum = max(a[i]*1ll, sum+a[i]);
			mid = max(mid, sum);
		}

		if(k==1)
		{
			printf("%lld\n", mid);
			continue;
		}

		ans = max(full*k, mid);
		ans = max(ans, left+right);
		ans = max(ans, left+right + full*(k-2));
		//cout<<left<<" "<<right<<" "<<mid<<" "<<full<<endl;

		printf("%lld\n", ans);
	}
}