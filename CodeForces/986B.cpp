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
	int n, cnt=0;
	int a[1000009], pos[1000009];

	read(n);
	for(int i=1; i<=n; i++)
	{
		read(a[i]);
		pos[a[i]] = i;
	}

	for(int i=1; i<=n; i++)
	{
		if(a[i] == i)
			continue;
		cnt++;
		a[pos[i]] = a[i];
		pos[a[i]] = pos[i];
	}

	if(cnt%2 == 0 && n%2==0)
	{
		printf("Petr\n");
		return 0;
	}
	if(cnt%2 == 1 && n%2==1)
	{
		printf("Petr\n");
		return 0;
	}
	printf("Um_nik\n");
}