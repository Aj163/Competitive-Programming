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
	int a, b, c, d, x=0;
	char ans[59][59];

	read2(a, b);
	read2(c, d);

	for(int i=0; i<50; i++)
		ans[i][50] = '\0';

	if(d>1)
	{
		a--;
		while(1)
		{
			for(int i=0; i<50; i++)
			{
				if(x%2==0)
				{
					if(i%2 == 0 && d>1)
					{
						ans[i][x] = 'D';
						d--;
					}
					else
						ans[i][x] = 'A';
				}
				else
					ans[i][x] = 'A';
			}
			
			x++;
			if(x%2==0 && d==1)
				break;
		}

		for(int i=0; i<50; i++)
			ans[i][x] = ans[i][x+1] = 'D';
		x+=2;

	}

	while(x<50)
	{
		for(int i=0; i<50; i++)
		{
			if(x%2 == 0)
			{
				if(a && i%2==0)
				{
					a--;
					ans[i][x] = 'A';
				}
				else if(b && i%2==0)
				{
					b--;
					ans[i][x] = 'B';
				}
				else if(c && i%2==0)
				{
					c--;
					ans[i][x] = 'C';
				}
				else
					ans[i][x] = 'D';
			}
			else
				ans[i][x] = 'D';
		}
		x++;
	}

	printf("50 50\n");
	for(int i=0; i<50; i++)
		printf("%s\n", ans[i]);
}