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
	const int N = 3e8+9;
	int l, r;
	bitset<N> b;

	read2(l, r);
	b.set();

	for(int i=3; i*i<=r; i+=2)
		if(b[i])
		{
			for(int j=i*i; j<=r; j+=i)
				b[j] = 0;
		}

	int ans = 0;
	if(l<=2 && 2<=r)
		ans++;

	int k = 4*ceil((l-1)*1.0/4) +1;
	k = max(k, 5);
	for(; k<=r; k+=4)
		if(b[k])
			ans++;

	printf("%d\n", ans);
}