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
	int n, a[200009], ans;
	int done[200009];

	memset(done, 0, sizeof(done));
	read(n);
	f(i, n)
		read(a[i]);

	ans = a[n-1];
	F_(i, n-1, -1, 1)
	{
		if(done[a[i]] == 0)
		{
			done[a[i]] = 1;
			ans = a[i];
		}
	}

	printf("%d\n", ans);
}