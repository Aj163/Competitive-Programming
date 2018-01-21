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

#define max (1<<21)
int tree[max];

void build(int node)
{
	if(node>=max/2)
		return;

	build(node*2);
	build(node*2 +1);

	tree[node] = __gcd(tree[node*2], tree[node*2 +1]);
}

void update(int node, int a, int b, int i, int j, int val)
{
	
	if(j<a || b<i || a>b)
		return;

	if(node>=max/2)
	{
		tree[node] = val;
		return;
	}

	update(node*2, a, (a+b)/2, i, j, val);
	update(node*2 +1, (a+b)/2 +1, b, i, j, val);

	tree[node] = __gcd(tree[node*2], tree[node*2 +1]);
}

int query(int node, int a, int b, int i, int j, int x)
{
	if(j<a || b<i || a>b)
		return 0;

	if(i<=a && j>=b)
		if(tree[node] % x == 0) return 0;

	if(node>=max/2)
		return 1;

	int a1 = query(node*2, a, (a+b)/2, i, j, x);

	if(a1 > 1)
		return 2;

	int a2 = query(node*2 +1, (a+b)/2 +1, b, i, j, x);
	return a1+a2;
}

void init(int size_of_input_array)
{
	int n = size_of_input_array;
	f(i, n)
		cin>>tree[i+max/2];

	F(i, n, max/2, 1)
		tree[i+max/2] = 0;

	build(1);
}

int main()
{
	int n, q, l, r, x, i, y, t;
	read(n);
	init(n);

	read(q);
	f(z, q)
	{
		read(t);
		if(t==1)
		{
			read3(l, r, x);
			if(query(1, max/2, max-1, max/2+l-1, max/2+r-1, x) > 1)
				printf("NO\n");
			else
				printf("YES\n");
		}
		else
		{
			read2(i, y);
			update(1, max/2, max-1, max/2+i-1, max/2+i-1, y);
		}
	}	
}