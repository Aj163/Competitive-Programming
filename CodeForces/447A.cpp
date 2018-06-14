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
	int n, p, a;
	bool d[309], flag=1;

	memset(d, 0, sizeof(d));
	read2(p, n);
	for(int i=0; i<n; i++)
	{
		read(a);
		if(d[a%p] && flag)
		{
			printf("%d\n", i+1);
			flag=0;
		}
		d[a%p] = 1;
	}

	if(flag)
		printf("-1\n");
}
