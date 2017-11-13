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

int a[24], t1, t2;

int check()
{
	f(i, 6)
	{
		if(a[i*4] == a[i*4 + 1] && a[i*4 +1] == a[i*4 + 2] && a[i*4 +2] == a[i*4 + 3])
			continue;
		else
			return 0;
	}
	return 1;
}

int main()
{
	f(i, 24)
		read(a[i]);


	//case 1
	t1 = a[5];
	t2 = a[7];

	a[5] = a[9];
	a[7] = a[11];

	a[9] = a[22];
	a[11] = a[20];

	a[20] = a[3];
	a[22] = a[1];

	a[3] = t2;
	a[1] = t1;

	if(check())
	{
		printf("YES\n");
		return 0;
	}

	//case 2
	swap(a[5], a[22]);
	swap(a[7], a[20]);

	swap(a[3], a[11]);
	swap(a[1], a[9]);

	if(check())
	{
		printf("YES\n");
		return 0;
	}

	//Revert
	t1 = a[5];
	t2 = a[7];

	a[5] = a[9];
	a[7] = a[11];

	a[9] = a[22];
	a[11] = a[20];

	a[20] = a[3];
	a[22] = a[1];

	a[3] = t2;
	a[1] = t1;


	//case 3
	t1 = a[4];
	t2 = a[5];

	a[5] = a[13];
	a[4] = a[12];

	a[13] = a[21];
	a[12] = a[20];

	a[21] = a[17];
	a[20] = a[16];

	a[17] = t2;
	a[16] = t1;

	if(check())
	{
		printf("YES\n");
		return 0;
	}

	//case 4
	swap(a[4], a[20]);
	swap(a[5], a[21]);

	swap(a[13], a[17]);
	swap(a[12], a[16]);

	if(check())
	{
		printf("YES\n");
		return 0;
	}

	//Revert
	t1 = a[4];
	t2 = a[5];

	a[5] = a[13];
	a[4] = a[12];

	a[13] = a[21];
	a[12] = a[20];

	a[21] = a[17];
	a[20] = a[16];

	a[17] = t2;
	a[16] = t1;


	//case 5
	t1 = a[0];
	t2 = a[1];

	a[0] = a[17];
	a[1] = a[19];

	a[17] = a[11];
	a[19] = a[10];

	a[11] = a[14];
	a[10] = a[12];

	a[14] = t1;
	a[12] = t2;

	if(check())
	{
		printf("YES\n");
		return 0;
	}

	//case 6
	swap(a[12], a[19]);
	swap(a[14], a[17]);

	swap(a[0], a[11]);
	swap(a[1], a[10]);

	if(check())
	{
		printf("YES\n");
		return 0;
	}

	printf("NO\n");
}