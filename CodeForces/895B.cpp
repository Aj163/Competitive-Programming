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

int n, x, k, a[100005];
map<int, int> m;

int up(int i)
{
	int l=m[a[i]], r=n-1, mid, pos=-2;

	while(l<=r)
	{
		mid = (l+r)/2;
		if(a[mid]/x - ceil(a[i]*1.0/x) +1 > k)
			r = mid-1;
		else if(a[mid]/x - ceil(a[i]*1.0/x) +1 < k)
			l = mid+1;
		else
		{
			pos = mid;
			l = mid+1;
		}
	}

	return pos;
}

int down(int i)
{
	int l=m[a[i]], r=n-1, mid, pos=-1;

	while(l<=r)
	{
		mid = (l+r)/2;
		if(a[mid]/x - ceil(a[i]*1.0/x) +1 > k)
			r = mid-1;
		else if(a[mid]/x - ceil(a[i]*1.0/x) +1 < k)
			l = mid+1;
		else
		{
			pos = mid;
			r = mid-1;
		}
	}

	return pos;
}

int main()
{
	ll ans=0;

	read3(n, x, k);
	f(i, n)
		read(a[i]);

	sort(a, a+n);

	f(i, n)
	{
		if(m.find(a[i]) == m.end())
			m[a[i]] = i;
		ans += up(i) - down(i) +1;
	}

	cout<<ans;
}