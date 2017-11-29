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

#define max (1<<19)

vi v[100009], t[100009];
int tree[100009], depth[100009];

void dfs(int x, int d, int num, int p)
{
	tree[x] = num;
	depth[x] = d;
	t[num].pb(0);

	f(i, v[x].size())
		if(v[x][i] != p)
			dfs(v[x][i], d+1, num, x);
}

void update(int p, int x, int num)
{
	for(int i=p; i<t[num].size(); i += (i&(-i)))
		t[num][i] += x;
}

int query(int p, int num)
{
	int ret = 0;
	for(int i=p; i>0; i-=(i&(-i)))
		ret += t[num][i];
	return ret;
}

int main()
{
	int n, q, v1, v2, root = 0, t1, x, val, dist;

	read2(n, q);
	f(i, n-1)
	{
		read2(v1, v2);
		v1--;
		v2--;
		v[v1].pb(v2);
		v[v2].pb(v1);
	}

	f(i, v[0].size())
	{
		t[i].pb(0);
		dfs(v[0][i], 1, i, 0);
	}

	f(i, 100009)
		t[100008].pb(0);

	f(z, q)
	{
		read(t1);
		if(t1 == 0)
		{
			read3(x, val, dist);
			x--;

			if(x==0)
			{
				root += val;
				update(1, val, 100008);
				update(dist+1, -val, 100008);
			}
			else
			{
				if(dist>=depth[x])
				{
					int left = dist-depth[x];
					root += val;

					update(1, val, 100008);
					update(left+1, -val, 100008);
					update(left+1, val, tree[x]);
					update(depth[x]+dist+1, -val, tree[x]);
				}
				else
				{
					update(depth[x]-dist, val, tree[x]);
					update(depth[x]+dist+1, -val, tree[x]);
				}
			}
		}
		else
		{
			read(x);
			x--;
			if(x==0)
				printf("%d\n", root);
			else
				printf("%d\n", query(depth[x], tree[x]) + query(depth[x], 100008));
		}
	}
}