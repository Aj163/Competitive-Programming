By aj1729, contest: Good Bye 2017, problem: (B) New Year and Buggy Bot, Accepted, #

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

int n, m, l;
int arr[4] = {0,1,2,3};
char s[60][60], str[109];

bool valid(int x, int y)
{
	if(x<0 || x>=n || y<0 || y>=m)
		return 0;
	return 1;
}

int solve()
{
	int x = 0, y = 0, flag = 1;
	for(x=0; x<n; x++)
	{
		for(y=0; y<m; y++)
			if(s[x][y] == 'S')
			{
				flag = 0;
				break;
			}
		if(flag == 0)
			break;
	}

	int p = 0;
	while(p<l)
	{
		if(!valid(x, y))
			return 0;
		if(s[x][y] == '#')
			return 0;
		if(s[x][y] == 'E')
			return 1;

		if(arr[str[p] - '0'] == 0)
			x--;
		else if(arr[str[p] - '0'] == 1)
			x++;
		else if(arr[str[p] - '0'] == 2)
			y--;
		else if(arr[str[p] - '0'] == 3)
			y++;

		p++;
	}
	if(!valid(x, y))
		return 0;
	if(s[x][y] == '#')
		return 0;
	if(s[x][y] == 'E')
		return 1;
	return 0;
}

int main()
{
	read2(n, m);
	f(i, n)
		reads(s[i]);

	reads(str);
	l = strlen(str);

	int ans = 0;

	do
	{
		ans += solve();
	}while(next_permutation(arr, arr+4));

	printf("%d\n", ans);
}