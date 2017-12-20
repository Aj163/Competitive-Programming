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
 
int pow(int a, ll n, int m)
{
	if(n==0)
		return 1;
	if(n%2==0)
		return pow((a*1ll*a)%m, n/2, m);
	return (a*1ll*pow((a*1ll*a)%m, (n-1)/2, m))%m;
}
 
int main()
{
	ios::sync_with_stdio(false);
	int t, n1, n2, d1, d2;
	ll n;
 
	cin>>t;
	f(z, t)
	{
		cin>>n;
 
		if(n==1)
			cout<<"0 0\n";
		else if(n==2)
			cout<<"1 1\n";
		else
		{
			n1=(n-1)%M;
			d1 = ((2*n1) * 1ll * (2*n1-1))%M;
			n1 = ((n1 * 1ll * n1)%M * 1ll * (n1+1))%M;
			n1 = (n1 * 1ll * pow(d1, M-2, M))%M;
 
			n2=(n-1)%(M+2);
			d2 = ((2*n2) * 1ll * (2*n2-1))%(M+2);
			n2 = ((n2 * 1ll * n2)%(M+2) * 1ll * (n2+1))%(M+2);
			n2 = (n2 * 1ll * pow(d2, M, M+2))%(M+2);
 
			cout<<n1<<" "<<n2<<endl;
		}
	}
}  