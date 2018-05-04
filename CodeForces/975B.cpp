#include <bits/stdc++.h>
using namespace std;

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

void copy(ll a[], ll b[])
{
	for(int i=0; i<14; i++)
		b[i] = a[i];
}

int main()
{
	ll a[20], b[20];
	ll ans = -1, sum;

	for(int i=0; i<14; i++)
		cin>>a[i];

	for(int z=0; z<14; z++)
	{
		copy(a, b);
		sum = 0;
		int pos=z, cnt = b[z];
		b[z] = 0;

		for(int i=0; i<14; i++)
			b[i] += cnt/14;

		cnt %= 14;
		while(cnt--)
		{
			pos = (pos+1)%14;
			b[pos]++;
		}

		for(int i=0; i<14; i++)
			sum += (b[i]%2 == 0)*b[i];

		ans = max(ans, sum);
	}

	printf("%lld\n", ans);
}