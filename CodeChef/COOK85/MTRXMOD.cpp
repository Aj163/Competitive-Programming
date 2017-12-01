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
 
int n, q, a[1009][1009], p, zz[1009];
 
void prn()
{
	int b, prev;
	cout<<0<<" "<<-a[0][1]<<" ";
	prev = -a[0][1];
	zz[0] = 0;
	zz[1] = prev;
 
	F(i, 2, n, 1)
	{
		int k=0;
		while(k<i-1)
		{
			if(a[0][k]!=0)
				break;
			k++;
		}
		b = -a[0][i];
 
		if(a[k][i] != abs(zz[k]-b))
		{
			cout<<(-b)<<" ";
			zz[i] = -b;
		}
		else
		{
			cout<<b<<" ";
			zz[i] = b;
		}
	}
 
	cout<<endl;
}
 
int main()
{
	ios::sync_with_stdio(false);
	
 
	cin>>n>>q;
	f(i, n)
		f(j, n)
			cin>>a[i][j];
 
	prn();
 
	f(z, q)
	{
		cin>>p;
		p--;
		f(i, n)
		{
			cin>>a[i][p];
			a[p][i] = a[i][p];
		}
		prn();
	}
} 