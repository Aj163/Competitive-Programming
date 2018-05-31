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
	int x, y;

	read2(x, y);
	if(x == y || (x==2 && y==4) || (x==4 && y==2))
	{
		printf("=\n");
		return 0;
	}

	if(x*1.0*log(y) < y*1.0*log(x))
		printf(">\n");
	else
		printf("<\n");
}