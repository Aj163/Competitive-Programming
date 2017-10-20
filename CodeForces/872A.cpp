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
	int n, m, c, d;
	int a[20], b[20], ctr[10] = {0};

	read2(n, m);
	f(i, n)
	{
		read(a[i]);
		ctr[a[i]]++;
	}

	f(i, m)
	{
		read(b[i]);
		ctr[b[i]]++;
	}

	sort(a, a+n);
	sort(b, b+m);

	c = a[0];
	d = b[0];

	if(c+d == 0)
	{
		if(a[1]>b[1])
			c = a[1];
		else
			d = b[1];
	}

	int ans = min(c, d)*10 + max(c, d);
	F(i, 1, 10, 1)
	{
		if(ctr[i] >= 2)
		{
			ans = i;
			break;
		}
	}


	printf("%d\n", ans);
}