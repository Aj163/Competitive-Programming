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
	int n, max1, max2, ans = 1e7, cnt = -10;
	int a[100009], len[100009], tr[100009];

	read(n);
	f(i, n)
		read(a[i]);

	memset(len, 0, sizeof(len));
	memset(len, 0, sizeof(tr));

	if(n==1)
	{
		printf("%d\n", a[0]);
		return 0;
	}
	else if(n==2)
	{
		printf("%d\n", min(a[0], a[1]));
		return 0;
	}

	max1 = max(a[0], a[1]);
	max2 = min(a[0], a[1]);

	if(a[1] < a[0])
		len[a[0]]++;
	else
		tr[a[1]] = 1;

	tr[a[0]] = 1;

	F(i, 2, n, 1)
	{
		if(a[i] > max1)
		{
			tr[a[i]] = 1;
			max2 = max1;
			max1 = a[i];
		}
		else if(a[i]>max2)
		{
			len[max1]++;
			max2 = a[i];
		}
	}

	F(i, 1, n+1, 1)
	{
		//cout<<len[i]<<" "<<tr[i]<<endl;
		if(len[i] - tr[i] > cnt)
		{
			cnt = len[i] - tr[i];
			ans = i;
		}
		else if(len[i] - tr[i] == cnt)
			ans = min(ans, i);
	}

	printf("%d\n", ans);
}