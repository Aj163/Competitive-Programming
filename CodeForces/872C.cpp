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
	int q, n, ctr=0;
	read(q);
	f(i, q)
	{
		read(n);
		if(n<4 || n==5 || n==7 || n==11)
		{
			printf("-1\n");
			continue;
		}

		ctr = 0;

		if(n%4==3)
		{
			n-=15;
			ctr+=2;
		}
		else if(n%4==2)
		{
			n-=6;
			ctr++;
		}
		else if(n%4==1)
		{
			n-=9;
			ctr++;
		}
		ctr+=n/4;

		printf("%d\n", ctr);
	}
}