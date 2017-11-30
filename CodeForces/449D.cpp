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
	int n, t, ans=0;
	int p2[1<<20], cnt[1<<20];
	memset(cnt, 0, sizeof(cnt));

	read(n);
	f(i, n)
	{
		read(t);
		cnt[t]++;
	}

	p2[0] = 1;
	F(i, 1, (1<<20), 1)
		p2[i] = (p2[i-1]*2)%M;

	f(i, 20)
		F_(j, (1<<20)-1, -1, 1)
			if((j&(1<<i)) == 0)
				cnt[j] += cnt[j | (1<<i)];

	f(i, (1<<20))
	{
		if(__builtin_popcount(i)&1)
			ans = (ans-p2[cnt[i]] +M)%M;
		else
			ans = (ans+p2[cnt[i]])%M;
	}

	printf("%d\n", ans);
}