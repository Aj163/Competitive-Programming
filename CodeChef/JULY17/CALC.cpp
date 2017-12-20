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
	int t, n, b, k;
	ll ans1, ans2;
 
	cin>>t;
	f(z, t)
	{
		cin>>n>>b;
		if(b>n)
			cout<<"0\n";
		else
		{
			k=n/2/b;
			ans1=n-k*1ll*b;
			ans1=ans1*1ll*k;
 
			ans2=n-(k+1)*1ll*b;
			ans2=ans2*1ll*(k+1);
 
			if(ans1<ans2)
				cout<<ans2<<endl;
			else
				cout<<ans1<<endl;
		}
	}
} 