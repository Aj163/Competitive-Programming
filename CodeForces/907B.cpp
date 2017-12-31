#include <bits/stdc++.h>
using namespace std;

#define f(i, num) for(int i=0; i<num; i++) //0 - based indexing
#define f1(i, num) for(int i=1; i<=num; i++) //1 - based indexing
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define read(num) scanf("%d", &num)
#define read2(num1, num2) scanf("%d%d", &num1, &num2)
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3)
#define reads(str) scanf("%s", str)
#define readc(ch) scanf("%c", &ch)

#define M 1000000007
#define INF ((int)2e9)
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

int main()
{
	char s[20][20][5], t[20];
	int x, y, t1 = 0;

	f(i, 3)
		f(j, 3)
			reads(s[i][j]);
	//reads(t);
	f(i, 3)
		f(j, 3)
			reads(s[i+3][j]);
	//reads(t);
	f(i, 3)
		f(j, 3)
			reads(s[i+6][j]);

	read2(x, y);
	x--;
	y--;

	x%=3;
	y%=3;

	f(i, 3)
		f(j, 3)
			if(s[x*3+i][y][j] == '.')
				s[x*3+i][y][j] = '!', t1++;

	if(t1)
	{
		f(i, 9)
		{
			if(i==3 || i==6)
				printf("\n");
			f(j, 3)
				printf("%s ", s[i][j]);
			printf("\n");
		}
	}
	else
	{
		f(i, 9)
		{
			if(i==3 || i==6)
				printf("\n");
			f(j, 3)
			{	
				f(k, 3)
				{
					if(s[i][j][k] == '.')
						printf("!");	
					else
						printf("%c", s[i][j][k]);
				}
				printf(" ");
			}
			printf("\n");
		}
	}
}