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
	int t, l, ans, a, b;
	char s[200001];
 
	cin>>t;
	f(z, t)
	{
		cin>>s;
		a=0;
		b=0;
		ans=0;
		f(i, strlen(s))
		{
			if(s[i]=='<')
			{
				a++;
				b=0;
			}
			else if(s[i]=='>')
			{
				b++;
				a=0;
			}
			ans=max(ans, a);
			ans=max(ans, b);
		}
		cout<<ans+1<<endl;
	}
} 