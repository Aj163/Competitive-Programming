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
	int l, r, x, y, k, flag=0;

	cin>>l>>r>>x>>y>>k;
	F(i, x, y+1, 1)
	{
		if(i*1ll*k <= 1ll*r && i*1ll*k >= 1ll*l)
		{
			flag=1;
			break;
		}
	}

	if(flag)
		cout<<"YES";
	else
		cout<<"NO";
}