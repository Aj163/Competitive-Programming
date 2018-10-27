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
	int a, t, n, ans;
	map<ll, int> m;
	map<ll, int>::iterator it;

	read(t);
	f(z, t)
	{
		ans = 0;
		read(n);
		f(i, n)
		{
			read(a);
			m[a]++;
		}

		while(m.size())
		{
			it = m.begin();
			if((*it).second == 1)
			{
				m.erase(it);
				continue;
			}

			f(i, (*it).second -1)
				m[(*it).first*1ll*(i+2)]++;

			ans += (*it).second -1;
			m.erase(it);
		}

		printf("%d\n", ans);
	}
}