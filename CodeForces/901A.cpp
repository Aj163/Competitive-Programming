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

int main()
{
	int h, t = 1;
	int a[200009];

	read(h);
	f(i, h+1)
		read(a[i]);

	int flag = 1;
	f(i, h)
		if(a[i]>1 && a[i+1]>1)
		{
			flag = 0;
			break;
		}

	if(flag)
	{
		printf("perfect\n");
		return 0;
	}

	printf("ambiguous\n0 ");
	f1(i, h)
	{
		if(a[i]>1 && a[i-1]>1)
		{
			f(j, a[i]-1)
				printf("%d ", t);
			printf("%d ", t-1);

			t += a[i];
		}
		else
		{
			f(j, a[i])
				printf("%d ", t);

			t += a[i];
		}
	}

	printf("\n0 ");
	t = 1;
	f1(i, h)
	{
		f(j, a[i])
			printf("%d ", t);

		t += a[i];
	}
}