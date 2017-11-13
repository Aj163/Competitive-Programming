#include <bits/stdc++.h>
using namespace std;

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)
 
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

int main()
{
	int n, x = 1, count[3][10] = {0}, a, flag = 1;

	read(n);
	f(i, n)
		f(j, 6)
		{
			read(a);
			count[i][a]++;
		}

	while(flag)
	{
		flag = 0;
		if(x/100 != 0)
		{
			//printf("awgar\n");
			int t1 = x/100;
			int t2 = (x%100)/10;
			int t3 = x%10;

			if(count[0][t1] && count[1][t2] && count[2][t3])
			{
				flag = 1;
				x++;
				continue;
			}
			else if(count[0][t1] && count[2][t2] && count[1][t3])
			{
				flag = 1;
				x++;
				continue;
			}
			else if(count[1][t1] && count[2][t2] && count[0][t3])
			{
				flag = 1;
				x++;
				continue;
			}
			else if(count[1][t1] && count[0][t2] && count[2][t3])
			{
				flag = 1;
				x++;
				continue;
			}
			else if(count[2][t1] && count[1][t2] && count[0][t3])
			{
				flag = 1;
				x++;
				continue;
			}
			else if(count[2][t1] && count[0][t2] && count[1][t3])
			{
				flag = 1;
				x++;
				continue;
			}
		}
		else if(x/10 != 0)
		{
			//printf("sdfsd\n");
			int t1 = x/10;
			int t2 = x%10;

			if(count[0][t1] && count[1][t2])
			{
				flag = 1;
				x++;
				continue;
			}
			else if(count[0][t2] && count[1][t1])
			{
				flag = 1;
				x++;
				continue;
			}
			else if(count[1][t1] && count[2][t2])
			{
				flag = 1;
				x++;
				continue;
			}
			else if(count[1][t2] && count[2][t1])
			{
				flag = 1;
				x++;
				continue;
			}
			else if(count[2][t1] && count[0][t2])
			{
				flag = 1;
				x++;
				continue;
			}
			else if(count[2][t2] && count[0][t1])
			{
				flag = 1;
				x++;
				continue;
			}
		}
		else
		{
			//printf("34rgr\n");
			if(count[0][x] || count[1][x] || count[2][x])
			{

				flag = 1;
				x++;
				continue;
			}
			else
			{
				flag = 0;
				break;
			}
		}
	}

	printf("%d\n", x-1);
}