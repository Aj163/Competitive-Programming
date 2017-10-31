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
	int n, a, b, ans, t;
	pii p[1009];

	read(n);
	f(i, n)
	{
		read2(a, b);
		p[i] = mp(a, b);
	}

	ans = p[0].first;
	F(i, 1, n, 1)
	{
		t = 0;
		while(p[i].first + p[i].second*t <=ans)
			t++;

		ans = p[i].first + p[i].second*t;
	}

	printf("%d\n", ans);
}