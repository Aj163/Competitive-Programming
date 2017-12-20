#include <bits/stdc++.h>
using namespace std;

#define f(i, num) for(int i=0; i<num; i++) //0 - based indexing
#define f1(i, num) for(int i=1; i<=num; i++) //1 - based indexing
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

int n, m;
pii p[109];

int main()
{
	int a, b;
	read2(n, m);
	f(i, n)
	{
		read2(a, b);
		p[i] = mp(a, b);
	}

	int flag = 1, temp = 0;
	if(p[0].first != 0)
		flag = 0;

	temp = p[0].second;
	F(i, 1, n, 1)
	{
		if(temp<p[i].first)
		{
			flag = 0;
			break;
		}
		temp = max(temp, p[i].second);
	}

	if(temp == m && flag)
		printf("YES\n");
	else
		printf("NO\n");
}