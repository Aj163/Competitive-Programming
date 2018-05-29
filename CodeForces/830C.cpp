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
	int n, a[109];
	set<int> s;
	ll k;

	read(n);
	readll(k);
	for(int i=0; i<n; i++)
	{
		read(a[i]);
		k += a[i];

		for(int j=1; j*j<=a[i]; j++)
		{
			s.insert(j);
			s.insert(ceil(a[i]*1.0/j));
		}
	}

	ll ans = 1;
	for(auto it : s)
	{
		ll sum = 0;
		for(int i=0; i<n; i++)
			sum += ceil(a[i]*1.0/it);

		if(it <= k/sum)
			ans = max(ans, k/sum);
	}

	printf("%lld\n", ans);
}