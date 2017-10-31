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

int n, k, last, pos, x, y, sum, t3, ans = 0;
ll l, c, t, t2;
int a[1000009], dp[1000009][2], p[1000009];

void solve(int i, int j)
{
	t = (c-j+1)%M;
	if(i>last && l%n)
		t = (t-1+M)%M;
	t2 = (t*dp[i][j&1])%M;
	ans = (ans + t2)%M;
}

int main()
{
	cin>>n>>l>>k;

	c = l/n;
	last = (l-1)%n;

	if(l%n)
		c++;

	k = min((ll)k, c);
	f(i, n)
	{
		read(a[i]);
		dp[i][1] = 1;
		p[i] = i;
		solve(i, 1);
	}

	sort(p, p + n, [](const int &i, const int &j){return pii(a[i], i) < pii(a[j], j);});
	pos = 0;

	F(j, 2, k+1, 1)
	{
		pos = 0;
		x = j & 1;
		y = 1-x;

		sum = 0;
		f(k, n)
		{
			t3 = p[k];
			while(pos < n && a[p[pos]] <= a[t3])
				sum = (sum + dp[p[pos++]][y])%M;
			dp[t3][x] = sum;
			solve(t3, j);
		}
	}

	printf("%d\n", ans);
}