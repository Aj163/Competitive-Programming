#include <bits/stdc++.h>
using namespace std;

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)
 
#define read(num) scanf("%d", &num)
#define read2(num1, num2) scanf("%d%d", &num1, &num2)
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3)
#define reads(str) scanf("%s", str)
#define readc(ch) scanf("%c", &ch)
 
#define M 1000000007
#define pb push_back
#define mp make_pair
 
#define pii pair<int, int>
#define vi vector<int>
#define ll long long

int main()
{
	int n, a, init = 0, flag[10] = {0}, x[10] = {0}, it = 1023;
	int a1, a2, a3;
	char s[500];
	char c;
	
	read(n);
	f(i, n)
	{
		reads(s);
		c = s[0];
		read(a);

		if(c=='&')
		{
			it &= a;
			init &= a;
		}
		else if(c=='|')
		{
			it |= a;
			init |= a;
		}
		else
		{
			it ^= a;
			init ^= a;
		}
	}

	a1 = 0;
	a2 = 1023;
	a3 = 0;

	f(i, 10)
	{
		if((init&(1<<i))/(1<<i) == 1 && (it&(1<<i))/(1<<i) == 1)
			a1 |= (1<<i);
		else if((init&(1<<i))/(1<<i) == 0 && (it&(1<<i))/(1<<i) == 0)
			a2 &= (1023 - (1<<i));
		else if((init&(1<<i))/(1<<i) == 1 && (it&(1<<i))/(1<<i) == 0)
			a3 |= (1<<i);
	}

	printf("3\n");
	printf("| %d\n", a1);
	printf("& %d\n", a2);
	printf("^ %d\n", a3);
}