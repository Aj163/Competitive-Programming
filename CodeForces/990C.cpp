#include <bits/stdc++.h>
using namespace std;

#define read(num) scanf("%d", &num)
#define readll(num) scanf("%lld", &num)
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
	int n, l, a, b;
	ll ans = 0;
	map<pii, int> m;
	pii p[300009];
	char s[300009];

	read(n);
	for(int i=0; i<n; i++)
	{
		reads(s);
		l = strlen(s);
		a = b = 0;

		for(int j=0; j<l; j++)
		{
			if(s[j] == '(')
				b++;
			else
			{
				if(b>0)
					b--;
				else
					a++;
			}
		}

		m[mp(a, b)]++;
		p[i] = mp(a, b);
	}

	for(int i=0; i<n; i++)
		ans += m[mp(0, p[i].first)]*(p[i].second == 0);

	printf("%lld\n", ans);
}