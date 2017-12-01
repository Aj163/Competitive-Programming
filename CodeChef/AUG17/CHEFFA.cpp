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
 
int t, n, a[100];
int m[200][200][101];
 
int ans(int i, int n)
{
	int c=0, ctr=0;
	if(i==n-1)
	{	
		//f(i, n)
			//cout<<a[i]<<" ";
		//cout<<endl;
		return 1;
	}
 
	if(m[i][a[i]][a[i+1]] != -1)
		return m[i][a[i]][a[i+1]];
 
	c = (c+ans(i+1, n))%M;
 
	if(a[i]>0 && a[i+1]>0)
		n++;
 
	while(a[i]>0 && a[i+1]>0)
	{
		a[i]--;
		a[i+1]--;
		a[i+2]++;
 
		c = (c+ans(i+1, n))%M;
		ctr++;
	}
 
	a[i]+=ctr;
	a[i+1]+=ctr;
	a[i+2]-=ctr;
 
	return m[i][a[i]][a[i+1]] = c;
}
 
int main()
{
	ios::sync_with_stdio(false);
 
	cin>>t;
	f(z, t)
	{
		cin>>n;
		f(i, n)
			cin>>a[i];
		F(i, n, 100, 1)
			a[i] = 0;
 
		f(i, 200)
			f(j, 200)
				f(k, 101)
					m[i][j][k]=-1;
		
		cout<<ans(0, n)<<endl;
	}
} 