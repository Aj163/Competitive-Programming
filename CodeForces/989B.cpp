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
	int n, k;
	char a[2009];
	bool flag = 1;

	read2(n, k);
	reads(a);
	for(int i=0; i<n-k; i++)
	{
		if(a[i] == '.' || a[i+k] == '.')
			flag = 0;
		else if(a[i] != a[i+k])
			flag = 0;
	}

	if(flag)
	{
		printf("No\n");
		return 0;
	}

	for(int i=0; i<n-k; i++)
	{
		if(a[i] == '.' && a[i+k] == '.')
		{
			a[i] = '0';
			a[i+k] = '1';
		}
		else if(a[i] == '.' && a[i+k] != '.')
			a[i] = 1- (a[i+k] - '0') + '0';
		else if(a[i] != '.' && a[i+k] == '.')
			a[i+k] = 1- (a[i] - '0') + '0';
	}
	for(int i=n-k; i<n; i++)
		if(a[i] == '.')
			a[i] = '0';

	printf("%s\n", a);
}