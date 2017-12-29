#define maxn 1000009
int tree[maxn];

void update(int x, int delta)
{
	for(; x <= n; x += x&-x)
		tree[x] += delta;
}

int query(int x)
{
	int sum = 0;
	for(; x > 0; x -= x&-x)
		sum += tree[x];
	return sum;
}