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
	int t, c[30], l, vis[30];
    ll ans;
	char s[50009];
 
	cin>>t;
	f(z, t)
	{
		f(i, 26)
			cin>>c[i];
 
		cin>>s;
		l = strlen(s);
		memset(vis, 0, sizeof(vis));
		f(i, l)
		{
			vis[s[i]-'a']=1;
		}
 
		ans=0;
		f(i, 26)
			if(vis[i]==0)
				ans+=c[i];
 
		cout<<ans<<endl;
	}	
} 