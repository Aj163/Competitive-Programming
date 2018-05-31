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

int n, m, k, s, x, y;
vi v[100009], col[100009];
int dis[100009][109];

void bfs(int c)
{
	for(int i=0; i<100009; i++)
		dis[i][c] = 1e9;

	queue<int> q;
	for(int i=0; i<col[c].size(); i++)
	{
		dis[col[c][i]][c] = 0;
		q.push(col[c][i]);
	}

	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		for(int i=0; i<v[p].size(); i++)
			if(dis[v[p][i]][c] > dis[p][c] +1)
			{
				dis[v[p][i]][c] = dis[p][c] +1;
				q.push(v[p][i]);
			}
	}
}

int main()
{
	read2(n, m);
	read2(k, s);

	for(int i=1; i<=n; i++)
	{
		read(x);
		col[x].pb(i);
	}

	for(int i=0; i<m; i++)
	{
		read2(x, y);
		v[x].pb(y);
		v[y].pb(x);
	}

	for(int i=1; i<=k; i++)
		bfs(i);

	for(int i=1; i<=n; i++)
	{
		int temp[109];
		for(int j=1; j<=k; j++)
			temp[j] = dis[i][j];

		sort(temp+1, temp+k+1);
		int sum=0;
		for(int j=1; j<=s; j++)
			sum += temp[j];
		printf("%d ", sum);
	}
	printf("\n");
}