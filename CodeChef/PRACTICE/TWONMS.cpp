#include <bits/stdc++.h>
#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)
#define M 1000000007
#define PII pair<int, int>
#define VI vector<int>
#define VIT vector<int>::iterator
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t, n, a, b;

	cin>>t;
	f(i, t)
	{
		cin>>a>>b>>n;
		if(n%2==0)
			cout<<max(a, b)/min(a, b)<<endl;
		else
			cout<<max(a*2, b)/min(a*2, b)<<endl;
	}
}

