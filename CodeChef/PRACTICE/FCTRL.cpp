#include <bits/stdc++.h>

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define vit vector<int>::iterator
#define ll long long

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t, n, j=0, a[50];
	ll i, ans;

	i=5;
	while(i<=1000000000)
	{
		a[j++] = i;
		i = i*1ll*5;
	}

	cin>>t;
	f(z, t)
	{
		ans=0;
		cin>>n;
		f(i, j)
			ans+=n/a[i];

		cout<<ans<<endl;
	}
}