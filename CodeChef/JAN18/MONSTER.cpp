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

#define block 2009
int n, q, tot, cur = -1, x, y;
ll a[1<<18], ans[block], add[1<<18];
pii updates[block];

void invert()
{
	int mask = (1<<17) -1;
	bool in[1<<17];

	memset(in, 0, sizeof(in));
	f(i, 1<<17)
		if(in[i] == 0)
		{
			swap(add[i], add[mask-i]);
			in[i] = 1;
			in[mask-i] = 1;
		}
}

void update()
{
	int mask = (1<<17) -1;

	invert();
	for(int i=0; i<17; i++) 
		for(int m=0; m<=mask; m++)
			if(m & (1<<i))
				add[m] += add[m^(1<<i)];

	invert();
}

void answer()
{
	f(i, n)
	{
		if(a[i] - add[i] <= 0 && a[i]>0)
		{
			f(j, cur+1)
			{
				if((i & updates[j].first) == i)
				{

					a[i] -= updates[j].second;
					if(a[i] <= 0)
					{
						ans[j]++;
						break;
					}
				}
			}
		}
		else
			a[i] -= add[i];
	}
}

int main()
{
	read(n);
	f(i, (1<<18))
		a[i] = 1e17;
	f(i, n)
		scanf("%lld", &a[i]);

	tot = n;
	memset(add, 0, sizeof(add));
	memset(ans, 0, sizeof(ans));

	read(q);
	f(z, q)
	{
		cur++;
		read2(x, y);
		add[x%(1<<17)] += y;
		updates[cur] = mp(x, y);

		if(cur == 2000|| z==q-1)
		{
			//Push Updates & answer quesries
			update();
			answer();

			f(i, cur+1)
			{
				tot -= ans[i];
				printf("%d\n", tot);
			}

			//Reset
			cur = -1;
			memset(add, 0, sizeof(add));
			memset(ans, 0, sizeof(ans));
		}
	}
}