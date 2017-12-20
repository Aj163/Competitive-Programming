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
ll t, n, s, a[20000], flag;

cin>>t;
f(i, t)
{
	cin>>n>>s;
	f(j, n)
		cin>>a[j];

	sort(a, a+n);
	flag=0;

	f(j, n)
	{
		if(s == a[j]*1ll*(n-j))
		{
			cout<<a[j]<<endl;
			flag=1;
			break;
		}
		s-=a[j];
	}

	if(!flag)
		cout<<-1<<endl;
}
}