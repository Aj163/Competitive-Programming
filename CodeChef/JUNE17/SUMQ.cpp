#include <bits/stdc++.h>
#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)
#define M 1000000007
#define PII pair<int, int>
using namespace std;
 
int main()
{
	ios::sync_with_stdio(false);
	int t, p, q, r, ans, x, y;
	vector<int> a(100000), b(100000), c(100000);
	vector<int>::iterator it1, it2;
	int A[100000], B[100000], C[100000];
 
	cin>>t;
	f(i, t)
	{
		ans=0;
		cin>>p>>q>>r;
		f(j, p)
			cin>>a[j];
		f(j, q)
			cin>>b[j];
		f(j, r)
			cin>>c[j];
 
		sort(a.begin(), a.begin()+p);
		sort(b.begin(), b.begin()+q);
		sort(c.begin(), c.begin()+r);
 
		A[0]=a[0];
		B[0]=b[0];
		C[0]=c[0];
 
		F(j, 1, p, 1)
			A[j]=(A[j-1]+a[j])%M;
		F(j, 1, q, 1)
			B[j]=(B[j-1]+b[j])%M;
		F(j, 1, r, 1)
			C[j]=(C[j-1]+c[j])%M;
 
		f(j, q)
		{
			it1=upper_bound(a.begin(), a.begin()+p, b[j]);
			it2=upper_bound(c.begin(), c.begin()+r, b[j]);
			if(it1-a.begin()<=0 || it2-c.begin()<=0)
				continue;
			x=it1-a.begin()-1;
			y=it2-c.begin()-1;
 
			ans=(A[x]*1ll*C[y]+ans)%M;
			ans=(((A[x]*1ll*(y+1))%M)*1ll*b[j]+ans)%M;
			ans=(((C[y]*1ll*(x+1))%M)*1ll*b[j]+ans)%M;
			ans=(((((b[j]*1ll*b[j])%M)*1ll*(x+1))%M)*1ll*(y+1)+ans)%M;
		}
		cout<<ans<<endl;
	}
} 