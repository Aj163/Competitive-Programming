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

int n, ans;
int a[100009], id[100009], siz[100009];
pii p[100009];
map<int, int> cnt;

int root(int x)
{
	while(id[x] != x)
	{
		id[x] = id[id[x]];
		x = id[x];
	}

	return x;
}

void unite(int x, int y)
{
	int x1 = root(x);
	int y1 = root(y);

	cnt[siz[x1]]--;
	if(cnt[siz[x1]] == 0)
		cnt.erase(cnt.find(siz[x1]));

	cnt[siz[y1]]--;
	if(cnt[siz[y1]] == 0)
		cnt.erase(cnt.find(siz[y1]));

	siz[y1] += siz[x1];
	cnt[siz[y1]]++;
	id[x1] = y1;
}

int main()
{
	read(n);
	for(int i=0; i<n; i++)
	{
		read(a[i]);
		p[i] = mp(a[i], i);
	}

	sort(p, p+n);

	for(int i=0; i<100009; i++)
	{
		siz[i] = 1;
		id[i] = i;
	}

	int maxi = -1;

	for(int i=0; i<n; i++)
	{
		cnt[1]++;
		if(p[i].second +1 < n && a[p[i].second +1] <= p[i].first)
			unite(p[i].second, p[i].second +1);

		if(p[i].second -1 >=0 && a[p[i].second -1] <= p[i].first)
			unite(p[i].second, p[i].second -1);

		if(cnt.size() == 1 && (cnt.begin())->second > maxi)
		{
			maxi = (cnt.begin())->second;
			ans = p[i].first +1;
		}
	}

	printf("%d\n", ans);
}