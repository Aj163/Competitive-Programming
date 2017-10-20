#include <bits/stdc++.h>
//#include <unordered_map>
 
#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)
 
#define read(num) scanf("%d", &num)
#define read2(numa, num2) scanf("%d%d", &numa, &num2)
#define read3(numa, num2, num3) scanf("%d%d%d", &numa, &num2, &num3)
#define reads(str) scanf("%s", str)
#define readc(ch) scanf("%c", &ch)
 
#define M 1000000007
#define pb push_back
#define mp make_pair
 
#define pii pair<int, int>
#define vi vector<int>
#define ll long long
 
using namespace std;

int main()
{
	int n, ctr=1;
	int a[300009], p;
	int x[300009];

	read(n);
	f(i, n)
	{
		read(a[i]);
		a[i]--;
	}

	memset(x, 0, sizeof(x));
	p = n-1;

	printf("1 ");
	f(i, n)
	{
		if(a[i] == p)
		{
			x[a[i]] = 1;
			p--;
			while(p>-1 && x[p] == 1)
			{
				ctr--;
				p--;
			}
			printf("%d ", ctr);
		}
		else
		{
			ctr++;
			printf("%d ", ctr);
			x[a[i]] = 1;
		}
	}
}