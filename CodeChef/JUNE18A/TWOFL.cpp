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

int n, m, siz, siz2;
int a[2009][2009];
ll ans = 0;
ll sizes[2009][2009];
pii id[2009][2009];
map<pii, vector<pair<pii, pii> > > edges;
pair<pii, pii> changes[4000009];
pair<pii, int> changeSize[4000009];

void init()
{
	for(int i=0; i<2009; i++)
		for(int j=0; j<2009; j++)
		{
			sizes[i][j] = 1;
			id[i][j] = mp(i, j);
		}
}

int prrt =1;

pii roots(int x, int y, bool prt=0)
{
	while(id[x][y] != mp(x, y))
	{
		//changes
		changes[siz++] = mp(mp(x, y), id[x][y]);

		int xx = id[x][y].first, yy = id[x][y].second;
		id[x][y] = id[xx][yy];
		pii z = id[x][y];
		x = z.first;
		y = z.second;	
	}

	return mp(x, y);
}

void unionize(int aa, int bb, int x, int y)
{
	pii p = roots(aa, bb);
	pii q = roots(x, y);

	if(p == q)
		return;

	//changes
	changes[siz++] = mp(p, p);
	changeSize[siz2++] = mp(q, sizes[q.first][q.second]);

	id[p.first][p.second] = q;
	sizes[q.first][q.second] += sizes[p.first][p.second];
	ans = max(ans, sizes[q.first][q.second]);
}

void reverse()
{
	for(int i=siz-1; i>=0; i--)
		id[changes[i].first.first][changes[i].first.second] = changes[i].second;
	for(int i=siz2-1; i>=0; i--)
		sizes[changeSize[i].first.first][changeSize[i].first.second] = changeSize[i].second;
	siz = siz2 = 0;
}

void print()
{
	printf("\n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
			printf("%lld ", sizes[i][j]);
		printf("\n");
	}
	printf("\n");
}

int main()
{
	read2(n, m);
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			read(a[i][j]);

	init();
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			siz = siz2 = 0;

			if(i>0)
			{
				if(a[i][j] == a[i-1][j])
					unionize(i, j, i-1, j);
				else
					edges[mp(min(a[i][j], a[i-1][j]), max(a[i][j], a[i-1][j]))].pb(mp(mp(i, j), mp(i-1, j)));
			}
			if(j>0)
			{
				if(a[i][j] == a[i][j-1])
					unionize(i, j, i, j-1);
				else
					edges[mp(min(a[i][j], a[i][j-1]), max(a[i][j], a[i][j-1]))].pb(mp(mp(i, j), mp(i, j-1)));
			}
		}

	for(auto it : edges)
	{
		siz = siz2 = 0;
		for(auto iter : it.second)
			unionize(iter.first.first, iter.first.second, iter.second.first, iter.second.second);

		reverse();
	}

	printf("%lld\n", ans);
}