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
	ll a, b;

	readll(a);
	readll(b);

	ll c = max(a, b), d = min(a, b);
	for(int i=60; i>=0; i--)
		if(((bool)(c & (1ll<<i))) != ((bool)(d & (1ll<<i))))
		{
			printf("%lld\n", (1ll<<(i+1)) -1);
			return 0;
		}

	printf("0\n");
}
