#include <bits/stdc++.h>

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define vit vector<int>::iterator
#define ll long long

using namespace std;

#define maxi (1<<21)

pair< pii, pii > inf = mp(mp(0, 0), mp(0, 0));
int lazy[maxi];
pair< pii, pii > tree[maxi];

int max(int a, int b, int c)
{
	return max(a, max(b, c));
}

void build(int node)
{
	if(node>=maxi/2)
		return;

	build(node*2);
	build(node*2 +1);

	int a1 = tree[node*2].first.first, a2 = tree[node*2 +1].first.first;
	int b1 = tree[node*2].first.second, b2 = tree[node*2 +1].first.second;
	int c1 = tree[node*2].second.first, c2 = tree[node*2 +1].second.first;
	int d1 = tree[node*2].second.second, d2 = tree[node*2 +1].second.second;

	tree[node] = mp(mp(a1+a2, b1+b2), mp(max(a1+c2, b1+b2, c1+b2), max(a1+a2, b1+d2, d1+a2)));
}

void update(int node, int a, int b, int i, int j)
{
	if(lazy[node]%2 == 1)
	{
		int t = tree[node].first.first;
		tree[node].first.first = tree[node].first.second;
		tree[node].first.second = t;

		t = tree[node].second.first;
		tree[node].second.first = tree[node].second.second;
		tree[node].second.second = t;

		if(node < maxi/2)
		{
			lazy[node*2]++;
			lazy[node*2 +1]++;
		}
		lazy[node] = 0;
	}
	
	if(j<a || b<i || a>b)
		return;

	if(i<=a && j>=b)
	{
		int t = tree[node].first.first;
		tree[node].first.first = tree[node].first.second;
		tree[node].first.second = t;

		t = tree[node].second.first;
		tree[node].second.first = tree[node].second.second;
		tree[node].second.second = t;

		if(node<maxi/2)
		{
			lazy[node*2]++;
			lazy[node*2 +1]++;
		}
		return;
	}

	update(node*2, a, (a+b)/2, i, j);
	update(node*2 +1, (a+b)/2 +1, b, i, j);

	int a1 = tree[node*2].first.first, a2 = tree[node*2 +1].first.first;
	int b1 = tree[node*2].first.second, b2 = tree[node*2 +1].first.second;
	int c1 = tree[node*2].second.first, c2 = tree[node*2 +1].second.first;
	int d1 = tree[node*2].second.second, d2 = tree[node*2 +1].second.second;

	tree[node] = mp(mp(a1+a2, b1+b2), mp(max(a1+c2, b1+b2, c1+b2), max(a1+a2, b1+d2, d1+a2)));
}

int main()
{
	ios::sync_with_stdio(false);
	int n, q, a, b;
	char c, s[10];

	cin>>n>>q;
	f(i, n)
	{
		cin>>c;
		if(c=='4')
			tree[i+maxi/2] = mp(mp(1, 0), mp(1, 1));
		else
			tree[i+maxi/2] = mp(mp(0, 1), mp(1, 1));
	}

	F(i, n, maxi/2, 1)
		tree[i+maxi/2] = inf;

	f(i, maxi)
		lazy[i] = 0;

	build(1);

	f(i, q)
	{
		cin>>s;
		if(!strcmp(s, "count"))
			cout<<tree[1].second.first<<endl;
		else
		{
			cin>>a>>b;
			a--;
			b--;
			update(1, maxi/2, maxi-1, a+maxi/2, b+maxi/2);
		}

		/*F(i, 1, maxi, 1)
			display(tree[i]);
		cout<<endl;*/
	}
}