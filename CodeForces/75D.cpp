#include <bits/stdc++.h>
using namespace std;

#define f(i, num) for(int i=0; i<num; i++)
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
	int n, l, t, t1;
	ll sum, ans;
	int a[5009], c[250009];
	ll left[5009], full[5009], right[5009], inans[5009];

	read2(n, t);
	f(z, n)
	{
		read(l);
		f(i, l)
			read(a[i]);

		//In-ans & Full
		sum = -1e16;
		inans[z] = -1e16;
		full[z] = 0;
		f(i, l)
		{
			sum = max(sum+a[i]*1ll, a[i]*1ll);
			inans[z] = max(inans[z], sum);
			full[z] += a[i];
		}

		//Left
		left[z] = a[0];
		sum = a[0];
		F(i, 1, l, 1)
		{
			sum += a[i];
			left[z] = max(left[z], sum);
		}

		//Right
		right[z] = a[l-1];
		sum = a[l-1];
		F_(i, l-2, -1, 1)
		{
			sum += a[i];
			right[z] = max(right[z], sum);
		}
	}

	ans = -1e16;

	f(i, t)
	{
		read(c[i]);
		c[i]--;
		ans = max(ans, inans[c[i]]);
	}

	sum = right[c[0]];

	F(i, 1, t, 1)
	{
		ans = max(sum+left[c[i]], ans);
		sum = max(sum+full[c[i]], right[c[i]]);
		ans = max(ans, sum);
	}

	cout<<ans;
}