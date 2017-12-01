#include <bits/stdc++.h>
 
#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)
 
#define read(num) scanf("%d", &num);
#define read2(num1, num2) scanf("%d%d", &num1, &num2);
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3);
 
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
	int t, n, pos;
	int a[100009];
	ll b[100009], c[100009], m;
 
	read(t);
	f(z, t)
	{
		read(n);
		f(i, n)
			read(a[i]);
		b[0]=0;
		F(i, 1, n, 1)
			b[i] = b[i-1]+a[i];
 
		c[n-1]=a[n-1];
		F_(i, n-2, -1, 1)
			c[i] = c[i+1]+a[i];
 
		m=b[0]+c[0];
		pos=0;
		F(i, 1, n, 1)
			if(b[i]+c[i]<m)
			{
				m = b[i]+c[i];
				pos=i;
			}
 
		printf("%d\n", pos+1);
	}
}   