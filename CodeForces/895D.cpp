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

int power(int a, int n)
{
	if(n==0)
		return 1;
	if(n%2)
		return (a * 1ll * power((a*1ll*a)%M, (n-1)/2))%M;
	return power((a*1ll*a)%M, n/2);
}

int main()
{
	char sa[1000009], sb[1000009];
	int cnt[26], fact[1000009], invfact[1000009];
	int l, t1, t2, t3, t4;

	//Factorial and inverse factorial Precomputation
	fact[0] = 1;
	F(i, 1, 1000009, 1)
		fact[i] = (fact[i-1]*1ll*i)%M;

	invfact[1000008] = power(fact[1000008], M-2);
	F_(i, 1000007, -1, 1)
		invfact[i] = (invfact[i+1]*1ll*(i+1))%M;

	//Input
	reads(sa);
	reads(sb);
	l = strlen(sa);


	//String A
	memset(cnt, 0, sizeof(cnt));
	f(i, l)
		cnt[sa[i] - 'a']++;

	t1 = fact[l];
	t2=0;
	f(i, 26)
		t1 = (t1*1ll*invfact[cnt[i]])%M;

	f(i, l)
	{
		t1 = (t1 * 1ll * invfact[l-i])%M;
		t1 = (t1 * 1ll * fact[l-i-1])%M;
		f(j, sa[i]-'a')
		{
			if(!cnt[j])
				continue;

			t1 = (t1 * 1ll * fact[cnt[j]])%M;
			cnt[j]--;
			t1 = (t1 * 1ll * invfact[cnt[j]])%M;

			t2 = (t2+t1)%M;

			t1 = (t1 * 1ll * fact[cnt[j]])%M;
			cnt[j]++;
			t1 = (t1 * 1ll * invfact[cnt[j]])%M;
		}

		if(!cnt[sa[i] - 'a'])
			break;

		t1 = (t1 * 1ll * fact[cnt[sa[i] - 'a']])%M;
		cnt[sa[i] - 'a']--;
		t1 = (t1 * 1ll * invfact[cnt[sa[i] - 'a']])%M;
	}

	//String B
	memset(cnt, 0, sizeof(cnt));
	f(i, l)
		cnt[sa[i] - 'a']++;

	t3 = fact[l];
	t4=0;
	f(i, 26)
		t3 = (t3*1ll*invfact[cnt[i]])%M;

	f(i, l)
	{
		t3 = (t3 * 1ll * invfact[l-i])%M;
		t3 = (t3 * 1ll * fact[l-i-1])%M;
		f(j, sb[i]-'a')
		{
			if(!cnt[j])
				continue;

			t3 = (t3 * 1ll * fact[cnt[j]])%M;
			cnt[j]--;
			t3 = (t3 * 1ll * invfact[cnt[j]])%M;

			t4 = (t4+t3)%M;

			t3 = (t3 * 1ll * fact[cnt[j]])%M;
			cnt[j]++;
			t3 = (t3 * 1ll * invfact[cnt[j]])%M;
		}

		if(!cnt[sb[i] - 'a'])
			break;

		t3 = (t3 * 1ll * fact[cnt[sb[i] - 'a']])%M;
		cnt[sb[i] - 'a']--;
		t3 = (t3 * 1ll * invfact[cnt[sb[i] - 'a']])%M;
	}

	printf("%d\n", (t4-t2-1+M)%M);
}