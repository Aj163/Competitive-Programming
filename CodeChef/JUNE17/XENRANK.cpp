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
	int t, u, v;
	cin>>t;

	f(i, t)
	{
		cin>>u>>v;
		cout<<(u+v)*1ll*(u+v+1)/2+u+1<<endl;
	}
}