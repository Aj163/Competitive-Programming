#include <bits/stdc++.h>
 
#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)
 
#define read(num) scanf("%d", &num);
#define read2(num1, num2) scanf("%d%d", &num1, &num2);
#define read3(num1, num2, num3) scanf("%d%d%d", &num1, &num2, &num3);
 
#define M 1000000007
#define pb push_back
#define mp make_pair
 
#define pii pair<int, int>
#define vi vector<int>
#define vit vector<int>::iterator
#define ll long long
 
using namespace std;
 
#define max (1<<19)
 
int query[max];
int tree[max];
 
void update(int tt[], int node, int a, int b, int i, int j, int val)
{	
	if(tt[node]!=0 && node<max/2)
	{
		tt[node*2] = (tt[node*2] + tt[node])%M;
		tt[node*2 +1] = (tt[node*2 +1] + tt[node])%M;
		tt[node] = 0;
	}
 
	if(j<a || b<i || a>b)
		return;
 
	if(i<=a && j>=b)
	{
		tt[node] = (val+tt[node])%M;
		return;
	}
 
	update(tt, node*2, a, (a+b)/2, i, j, val);
	update(tt, node*2 +1, (a+b)/2 +1, b, i, j, val);
}
 
void push_node(int tt[], int node, int a, int b, int i, int j)
{
	if(tt[node]!=0 && node<max/2)
	{
		tt[node*2] = (tt[node*2] + tt[node])%M;
		tt[node*2 +1] = (tt[node*2 +1] + tt[node])%M;
		tt[node] = 0;
	}
 
	if(j<a || b<i || a>b)
		return;
 
	if(i<=a && j>=b)
		return;
 
	push_node(tt, node*2, a, (a+b)/2, i, j);
	push_node(tt, node*2 +1, (a+b)/2 +1, b, i, j);
}
 
void update_all(int node, int a, int b)
{
	if(node>=max/2)
		return;
 
	tree[node*2] = (tree[node*2] + tree[node])%M;
	tree[node*2 +1] = (tree[node*2 +1] + tree[node])%M;
 
	update_all(node*2, a, (a+b)/2);
	update_all(node*2 +1, (a+b)/2 +1, b);
}
 
int main()
{
	int t, n, m, l, r, type;
	pair< int, pii > p[100009];
 
	read(t);
	f(z, t)
	{
		memset(query, 0, sizeof(query));
		memset(tree, 0, sizeof(tree));
 
		read2(n, m);
		f(i, m)
		{
			read3(type, l, r);
			p[i] = mp(type, mp(l, r));
		}
 
		F_(i, m-1, -1, 1)
		{
			if(p[i].first==2)
			{
				l = p[i].second.first -1 +max/2;
				r = p[i].second.second -1 +max/2;
				push_node(query, 1, max/2, max-1, i+max/2, i+max/2);
				update(query, 1, max/2, max-1, l, r, query[i+max/2] +1);
			}
			else
			{
				l = p[i].second.first -1 +max/2;
				r = p[i].second.second -1 +max/2;
				push_node(query, 1, max/2, max-1, i+max/2, i+max/2);
				update(tree, 1, max/2, max-1, l, r, query[i+max/2] +1);
			}
		}
 
		update_all(1, max/2, max-1);
		f(i, n)
			printf("%d ", tree[i+max/2]);
		printf("\n");
	}
} 