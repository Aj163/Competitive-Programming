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
	int t, n, d, avg, flag;
	ll sum, a[100000], ans;
 
	cin>>t;
	f(z, t)
	{
		cin>>n>>d;
		f(i, n)
			cin>>a[i];
 
		sum=0;
		ans=0;
		f(i, n)
			sum += a[i];
 
		if(sum%n)
		{
			cout<<-1<<endl;
			continue;
		}
		avg = sum/n;
 
		f(i, n-d)
		{
			ans += abs(a[i] - avg);
			a[i+d] -= (avg - a[i]);
			a[i] = avg;
		}
		
		flag=1;
		f(i, n)
			if(a[i]!=avg)
			{
				flag=0;
				break;
			}
 
		if(flag)
			cout<<ans<<endl;
		else
			cout<<-1<<endl;
	}
} 