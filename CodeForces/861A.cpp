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

int noz(ll a)
{
	if(a%10!=0)
		return 0;
	return 1+noz(a/10);
}

int hp5(ll a)
{
	if(a%5!=0)
		return 0;
	return 1+hp5(a/5);
}

int hp2(ll a)
{
	if(a%2!=0)
		return 0;
	return 1+hp2(a/2);
}

int main()
{
	int n, k, i=1, p;
	ll ans;

	read2(n, k);

	if(noz(n)>=k)
	{
		cout<<n;
		return 0;
	}

	while(1)
	{
		ans = n*1ll*i;
		if(noz(ans)>=k)
			break;
		
		if(hp2(ans) > hp5(ans))
			i*=5;
		else
			i*=2;
	}

	cout<<ans;
}