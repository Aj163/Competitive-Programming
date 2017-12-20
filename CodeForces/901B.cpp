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
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

bool can(int a[], int b[], int m)
{
	f(j, 158)
		if(abs(a[j] + b[j+1]) > 1)
			return 0;

	return 1;

}

int main()
{
	int n;
	int a[159], b[159], temp[159], temp2[159];

	read(n);
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(temp, 0, sizeof(temp));
	memset(temp2, 0, sizeof(temp2));

	a[0] = 1;

	f(i, n)
	{
		if(can(a, b, 1))
		{
			f(j, 159)
				temp[j] = a[j];

			f(j, 158)
				temp2[j+1] = a[j] + b[j+1];
			temp2[0] = b[0];

			f(j, 159)
			{
				a[j] = temp2[j];
				b[j] = temp[j];
			}
		}
		else
		{
			f(j, 159)
				temp[j] = a[j];

			f(j, 158)
				temp2[j+1] = -a[j] + b[j+1];
			temp2[0] = b[0];

			f(j, 159)
			{
				a[j] = temp2[j];
				b[j] = temp[j];
			}
		}
	}

	printf("%d\n", n);
	f(i, n+1)
		printf("%d ", a[i]*(a[n]/abs(a[n])));

	printf("\n%d\n", n-1);
	f(i, n)
		printf("%d ", b[i]*(b[n-1]/abs(b[n-1])));

	printf("\n");
}