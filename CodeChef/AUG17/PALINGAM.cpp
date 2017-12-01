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
	int t, x[26], y[26], l, flag;
	char a[501], b[501];
 
	cin>>t;
	f(z, t)
	{
		cin>>a>>b;
		l = strlen(a);
 
		f(i, 26)
		{
			x[i] = 0;
			y[i] = 0;
		}
 
		f(i, l)
		{
			x[a[i]-'a']++;
			y[b[i]-'a']++;
		}
 
		flag=0;
		f(i, 26)
			if(x[i]>=2 && y[i]==0)
				flag=1;
 
		if(!flag)
		{
			flag=1;
			f(i, 26)
				if(y[i]>0 && x[i]==0)
					flag=0;
 
			if(flag)
			{
				flag=0;
				f(i, 26)
					if(x[i]==1 && y[i]==0)
						flag=1;
			}
		}
 
		if(flag)
			cout<<"A\n";
		else
			cout<<"B\n";
	}
} 