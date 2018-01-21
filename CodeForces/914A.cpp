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
#define INF ((int)2e9)
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

bool sq(int a)
{
	f(i, 2000)
		if(i*i == a)
			return 0;

	return 1;
}

int main()
{
	int a, ans = -1e9, n;

	read(n);
	f(i, n)
	{
		read(a);
		if(a<0)
			ans = max(ans, a);
		else if(sq(a))
			ans = max(ans, a);
	}

	printf("%d\n", ans);
}