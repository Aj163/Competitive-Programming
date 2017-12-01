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

int n, ans, l, r, mid, pos, t1;
int a[1009], dp[1009][260], nxt[1009][1009];

int solve(int i, int mask, int jump)
{
	int maxi = -1e7;

	if(mask == 255)
		return 0;
	if(i>=n)
		return -1e7;
	if(dp[i][mask] != -1)
		return dp[i][mask];

	if(mask & (1<<a[i]))
		return dp[i][mask] = solve(i+1, mask, jump);
	
	maxi = max(maxi, solve(i+1, mask, jump));
	if(nxt[i][jump] != -10)
		maxi = max(maxi, solve(nxt[i][jump] +1, mask|(1<<a[i]), jump) +jump);
	if(nxt[i][jump+1] != -10)
		maxi = max(maxi, solve(nxt[i][jump +1] +1, mask|(1<<a[i]), jump) +jump+1);

	return dp[i][mask] = maxi;
}

int main()
{
	set<int> s;

	read(n);
	f(i, n)
	{
		read(a[i]);
		a[i]--;
		s.insert(a[i]);
	}

	f(i, 1009)
		f(j, 1009)
			nxt[i][j] = -10;

	f(j, n)
	{
		nxt[j][0] = j-1;
		pos = 1;
		F(k, j, n, 1)
			if(a[k] == a[j])
				nxt[j][pos++] = k;
	}

	ans = s.size();
	l = 0;
	r = n-1;
	while(l<=r)
	{
		mid = (l+r)/2;
		memset(dp, -1, sizeof(dp));
		t1 = solve(0, 0, mid);

		if(t1>=0)
			l = mid+1;
		else
			r = mid-1;

		ans = max(t1, ans);
	}

	printf("%d\n", ans);
}
