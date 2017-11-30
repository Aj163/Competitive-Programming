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
	char s[109];
	int l, pre[109], suf[109];
	ll ans = 0;

	reads(s);
	l = strlen(s);

	pre[0] = (s[0] == 'Q');
	suf[l-1] = (s[l-1] == 'Q');

	F(i, 1, l, 1)
		pre[i] = pre[i-1] + (s[i] == 'Q');

	F_(i, l-2, -1, 1)
		suf[i] = suf[i+1] + (s[i] == 'Q');

	f(i, l)
		if(s[i] == 'A')
			ans += pre[i]*suf[i];

	cout<<ans<<endl;
}