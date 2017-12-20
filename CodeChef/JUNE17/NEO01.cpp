#include <bits/stdc++.h>
#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)
#define M 1000000007
#define PII pair<int, int>
using namespace std;
 
int t, n, a[100000], c, pos;
long long ans, s;
 
long long sum(int i)
{
	long long as=0;
	F(j, i, n, 1)
		as+=a[j];
	return as;
}
 
int main()
{
	ios::sync_with_stdio(false);
 
	cin>>t;
	f(i, t)
	{
		cin>>n;
		f(j, n)
			cin>>a[j];
		sort(a, a+n, greater<int>());
		ans=a[0];
		pos=0;
		s=a[0];
		F(j, 1, n, 1)
		{
			s+=a[j];
			if(ans<=s*1ll*(j+1))
			{
				pos=j;
				ans=s*1ll*(j+1);
			}
		}
		ans+=sum(pos+1);
		cout<<ans<<endl;
	}
}