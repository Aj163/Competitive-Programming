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
	int a[100], t, n, c[10], flag;
 
	cin>>t;
	f(z, t)
	{
		f(i, 10)
			c[i] = 0;
 
		cin>>n;
		flag=3;
		f(i, n)
			cin>>a[i];
 
		if(a[0]!=1 || a[n-1]!=1)
		{
			cout<<"no\n";
			continue;
		}
 
		c[1]=1;
		F(i, 1, n, 1)
		{
			if(a[i]>7)
			{
				flag=0;
				break;
			}
 
			if(flag==3 && (a[i]!=a[i-1] && a[i] != a[i-1] +1))
			{
				flag=0;
				break;
			}
			if(flag==1 && (a[i]!=a[i-1] && a[i] != a[i-1] -1))
			{
				flag=0;
				break;
			}
 
			if(a[i]==7)
				flag=1;
 
			c[a[i]] += flag-2;
 
			//cout<<a[i]<<" ";
		}
 
		F(i, 1, 7, 1)
		{
			//cout<<c[i];
			if(c[i]!=0)
			{
				flag=0;
				break;
			}
		}
 
		if(flag)
			cout<<"yes\n";
		else
			cout<<"no\n";
	}
} 