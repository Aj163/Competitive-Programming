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
	int n, ans;
	char a[1009];

	read(n);
	reads(a);

	if(n==1)
	{
		if(a[0] == '0')
			printf("No\n");
		else
			printf("Yes\n");
		return 0;
	}

	if(a[0] == '0' && a[1] == '0')
	{
		printf("No\n");
		return 0;
	}

	if(a[n-1] == '0' && a[n-2] == '0')
	{
		printf("No\n");
		return 0;
	}

	bool flag = 1;
	for(int i=0; i<n-1; i++)
		if(a[i] == '1' && a[i+1] == '1')
			flag=0;

	if(flag == 0)
	{
		printf("No\n");
		return 0;
	}

	for(int i=0; i<n-2; i++)
		if(a[i] == '0' && a[i+1] == '0' && a[i+2] == '0')
			flag=0;

	if(flag == 0)
	{
		printf("No\n");
		return 0;
	}

	printf("Yes\n");
}