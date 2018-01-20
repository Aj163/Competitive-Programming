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
	int t, n, b;

	cin>>t;
	f(i, t)
	{
		cin>>n>>b;
		if(b==0)
		{
			if(n==2)
				cout<<"NO\n";
			else
			{
				cout<<"YES\n";
				F(j, 2, n+1, 1)
					cout<<1<<" "<<j<<endl;
			}
		}
		else if(b==1 && n==2)
			cout<<"YES\n1 2\n";
		else if(n<4*b)
			cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			F(j, 1, 2*b+1, 1)
				cout<<j<<" "<<j+1<<endl;
			F(j, 2*b+2, n+1, 1)
				cout<<2*b+1<<" "<<j<<endl;
		}
	}
}

