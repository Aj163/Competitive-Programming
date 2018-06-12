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
	int n, k, a;
	int c[300], s[300];

	memset(s, -1, sizeof(s));
	read2(n, k);
	for(int i=0; i<n; i++)
	{
		read(a);
		if(s[a] != -1)
			printf("%d ", c[a]);
		else
		{
			int el = max(a-k+1, 0);
			while(s[el] != -1)
			{
				if(s[el]+el >= a)
					break;
				el++;
			}

			if(s[el] == -1)
			{
				for(int j=el; j<=a; j++)
				{
					c[j] = el;
					s[j] = k - (j-el) -1;
				}
				printf("%d ", c[a]);
				continue;
			}

			for(int j=el+1; j<=a; j++)
			{
				s[j] = s[j-1] -1;
				c[j] = c[el];
			}
			printf("%d ", c[a]);
		}
	}
	printf("\n");
}