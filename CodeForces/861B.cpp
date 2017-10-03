#include <bits/stdc++.h>

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define read(num) scanf("%d", &num);
#define read2(num1, num2) scanf("%d%d", &num1, &num2);
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3);
#define reads(str) scanf("%s", str);
#define readc(ch) scanf("%c", ch);

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

using namespace std;

bool isv(char c)
{
	switch(c)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'u':
		case 'o':
			return 1;
		default:
			return 0;
	}
}

int main()
{
	int n, m, a, b, c=1, flag, ans=-1;
	pii p[109];

	read2(n, m);
	f(i, m)
	{
		read2(a, b);
		p[i] = mp(a, b);
	}

	F(f, 1, 101, 1)
	{
		flag=1;
		f(i, m)
		{
			if(ceil(p[i].first*1.0/f) != p[i].second)
			{
				flag=0;
				break;
			}
		}

		if(!flag)
			continue;
		if(flag)
		{
			if(ans==-1)
				ans = ceil(n*1.0/f);
			else if(ceil(n*1.0/f) != ans)
			{
				c=0;
				break;
			}
		}
	}

	if(c)
		printf("%d", ans);
	else
		printf("-1");
}