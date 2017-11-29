//Segment tree + Lazy propagation for RMQ(Range Minimum Query).
// max >= 2*Size of input array and a power of 2.

#define max (1<<20)
#define inf 1e18

ll lazy[max];
ll tree[max];

void build(int node)
{
	if(node>=max/2)
		return;

	build(node*2);
	build(node*2 +1);

	tree[node] = min(tree[node*2], tree[node*2 +1]);
}

void update(int node, int a, int b, int i, int j, ll val)
{
	if(lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if(node < max/2)
		{
			lazy[node*2] += lazy[node];
			lazy[node*2 +1] += lazy[node];
		}
		lazy[node] = 0;
	}
	
	if(j<a || b<i || a>b)
		return;

	if(i<=a && j>=b)
	{
		tree[node] += val;
		if(node<max/2)
		{
			lazy[node*2] += val;
			lazy[node*2 +1] += val;
		}
		return;
	}

	update(node*2, a, (a+b)/2, i, j, val);
	update(node*2 +1, (a+b)/2 +1, b, i, j, val);

	tree[node] = min(tree[node*2], tree[node*2 +1]);
}

ll query(int node, int a, int b, int i, int j)
{
	if(j<a || b<i || a>b)
		return inf;

	if(lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if(node < max/2)
		{
			lazy[node*2] += lazy[node];
			lazy[node*2 +1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if(i<=a && j>=b)
		return tree[node];

	ll a1 = query(node*2, a, (a+b)/2, i, j);
	ll a2 = query(node*2 +1, (a+b)/2 +1, b, i, j);
	return min(a1, a2);
}

void init(int size_of_input_array)
{
	int n = size_of_input_array;
	f(i, n)
		cin>>tree[i+max/2];

	F(i, n, max/2, 1)
		tree[i+max/2] = inf;

	f(i, max)
		lazy[i] = 0;

	build(1);
}