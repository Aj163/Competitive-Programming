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
	int t, n;
	int cnt[7];
	char s[10];

	map<string, int> m;

	m["mon"] = 1;
	m["tues"] = 2;
	m["wed"] = 3;
	m["thurs"] = 4;
	m["fri"] = 5;
	m["sat"] = 6;
	m["sun"] = 0;

	read(t);
	f(z, t)
	{
		read(n);
		reads(s);

		memset(cnt, 0,sizeof(cnt));

		int day = m[s];
		f(i, n)
		{
			cnt[day]++;
			day = (day+1)%7;
		}

		f(i, 6)
			printf("%d ", cnt[i+1]);
		printf("%d\n", cnt[0]);
	}
}