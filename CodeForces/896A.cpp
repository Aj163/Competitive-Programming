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

char f[1000] = "What are you doing at the end of the world? Are you busy? Will you save us?";
char x[1000] = "What are you doing while sending \"";
char y[1000] = "\"? Are you busy? Will you send \"";
char z[10] = "\"?";
int a, b, c, d;

ll getsize[100005];

char solve(ll n, ll k)
{
	ll a = getsize[n];
	if(a == -1)
	{
		if(k<b)
			return x[k];

		return solve(n-1, k-b);
	}

	if(k >= a)
		return '.';

	if(n==0)
		return f[k];

	ll a2 = getsize[n-1];

	if(k>= a2*2 + b+c)
		return z[k - (a2*2 + b+c)];

	if(k>= a2+b+c)
		return solve(n-1, k - (a2+b+c));

	if(k>= a2+b)
		return y[k - (a2+b)];

	if(k>= b)
		return solve(n-1, k - b);

	return x[k];		
}

int main()
{
	ll q, n, k, t;

	a = strlen(f);
	b = strlen(x);
	c = strlen(y);
	d = strlen(z);

	getsize[0] = a;
	F(i, 1, 100005, 1)
	{
		t = getsize[i-1];
		if(t==-1)
			getsize[i] = -1;
		else if(t*2 + d+b+c > 2.1e18)
			getsize[i] = -1;
		else
			getsize[i] = t*2 + d+b+c;
	}

	cin>>q;
	f(z, q)
	{
		cin>>n>>k;
		k--;

		printf("%c", solve(n, k));
	}
}