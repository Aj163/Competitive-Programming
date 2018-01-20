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
	int x;
	double p, ans;

	cin>>x>>p;

	if(x%5)
		cout<<p;
	else if(p-x-0.5<0)
		cout<<p;
	else
	{
		ans = p-x-0.5;
		cout<<ans;
	}
}