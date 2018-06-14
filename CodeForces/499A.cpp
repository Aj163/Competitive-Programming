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
	int n, r, x, y, ans=0, curr=1;

	read2(n, r);
	for(int i=0; i<n; i++)
	{
		read2(x, y);
		while(curr + r <= x)
			curr += r;
		while(curr <= y)
		{
			ans++;
			curr++;
		}
	}

	printf("%d\n", ans);
}