#include <bits/stdc++.h>
//#include <unordered_map>

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define read(num) scanf("%d", &num);
#define read2(numa, num2) scanf("%d%d", &numa, &num2);
#define read3(numa, num2, num3) scanf("%d%d%d", &numa, &num2, &num3);
#define reads(str) scanf("%s", str);
#define readc(ch) scanf("%c", ch);

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

using namespace std;

#define m 998244353

int power(int a, int n)
{
	if(n==0)
		return 1;
	if(n%2)
		return (a*1ll*power((a*1ll*a)%m, (n-1)/2))%m;
	return power((a*1ll*a)%m, n/2);
}

int main()
{
	int a, b, c, t1, t2, ans=1, t3, t4, t5, t6;
	int fact[5009];

	fact[0]=1;
	F(i, 1, 5009, 1)
		fact[i] = (fact[i-1]*1ll*i)%m;

	read3(a, b, c);
	
	t1 = min(a, b);
	t2 = max(a, b);
	t3 = 0;

	f(i, t1+1)
	{
		t4 = (fact[t2]*1ll*power(fact[t2-i], m-2))%m;
		t6 = (fact[t1]*1ll*power(fact[t1-i], m-2))%m;
		t5 = (t6*1ll*power(fact[i], m-2))%m;
		t3 = (t3 + t5*1ll*t4)%m;
	}


	ans = (ans*1ll*t3)%m;


	t1 = min(a, c);
	t2 = max(a, c);
	t3 = 0;

	f(i, t1+1)
	{
		t4 = (fact[t2]*1ll*power(fact[t2-i], m-2))%m;
		t6 = (fact[t1]*1ll*power(fact[t1-i], m-2))%m;
		t5 = (t6*1ll*power(fact[i], m-2))%m;
		t3 = (t3 + t5*1ll*t4)%m;
	}


	ans = (ans*1ll*t3)%m;


	t1 = min(c, b);
	t2 = max(c, b);
	t3 = 0;

	f(i, t1+1)
	{
		t4 = (fact[t2]*1ll*power(fact[t2-i], m-2))%m;
		t6 = (fact[t1]*1ll*power(fact[t1-i], m-2))%m;
		t5 = (t6*1ll*power(fact[i], m-2))%m;
		t3 = (t3 + t5*1ll*t4)%m;
	}


	ans = (ans*1ll*t3)%m;

	printf("%d", ans);
}