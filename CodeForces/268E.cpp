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

bool custom(pii &a, pii &b)
{
	double a1 = 1.0*b.first*b.second/100;
	double b1 = 1.0*a.first*a.second/100;

	a1 *= (100-a.second)*1.0/100;
	b1 *= (100-b.second)*1.0/100;

	return a1<b1;
}

int main()
{
	int n, a, b;
	double ans = 0.0, sum = 0.0;
	pii p[50009];

	read(n);
	for(int i=0; i<n; i++)
	{
		read2(a, b);
		p[i] = mp(a, b);
		ans += a*1.0;
	}

	sort(p, p+n, custom);
	for(int i=0; i<n; i++)
	{
		ans += (100-p[i].second)*1.0/100*sum;
		sum += 1.0*p[i].first*p[i].second/100;
	}

	printf("%0.11lf\n", ans);
}