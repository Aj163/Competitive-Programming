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

void print(int a[], int n)
{
	for(int i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main()
{
	int n, c, siz, t;
	int ans[1000009];
	vi div;

	read(t);
	while(t--)
	{
		read2(n, c);
		div.clear();
		siz=0;

		if(c==1)
		{
			for(int i=1; i<=n; i++)
				printf("%d ", i);
			printf("\n");
			continue;
		}
		if(n==1)
		{
			printf("%d\n", c);
			continue;
		}

		for(int i=1; i*i<=c; i++)
			if(c%i == 0)
			{
				div.pb(i);
				div.pb(c/i);
			}
		sort(div.begin(), div.end());

		bool flag=1;
		for(int i=0; i<div.size(); i++)
		{
			ans[0] = div[i] + n-1;
			int num = c/div[i];
			int prev = i;

			for(int j=1; j<n; j++)
			{
				ans[j] = ans[j-1];
				if(prev+1 < div.size() && div[prev+1] == div[prev] +1)
					prev++;

				while(prev>=0)
				{
					if(num % (div[prev]) == 0)
						break;
					prev--;
				}

				if(prev < 0)
					break;
				num /= div[prev];
				ans[j] = div[prev] + n-j-1;
			}

			if(num == 1)
				break;
		}

		for(int i=n-1; i>=0; i--)
			printf("%d ", ans[i]);
		printf("\n");
	}
}