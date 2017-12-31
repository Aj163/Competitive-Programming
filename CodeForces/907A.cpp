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
	int a, b, c, d, flag = 0;

	read2(a, b);
	read2(c, d);

	F(i, 1, 201, 1)
		F(j, 1, i, 1)
			F(k, 1, j, 1)
			{
				if(a<=i && b<=j && c<=k && d<=i && d<=j && d<=k && 2*d>=k && 2*d<j && 2*a>=i && 2*b>=j && 2*c>=k)
				{
					printf("%d\n%d\n%d\n", i, j, k);
					return 0;
				}
			}

	printf("-1\n");
}