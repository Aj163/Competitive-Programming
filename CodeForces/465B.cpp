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
	int n, ans=0;
	int a[1009];

	read(n);
	for(int i=1; i<=n; i++)
		read(a[i]);

	a[n+1] = a[0] = 0;
	for(int i=1; i<=n; i++)
	{
		if(a[i])
			ans++;
		if(a[i] && a[i+1]==0)
			ans++;
	}

	if(ans)
		ans--;

	printf("%d\n", ans);
}
