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

double lazy_add[max];
double lazy_mult[max];
double tree[max];

int n, q, t, l1, r1, l2, r2, l, r, t1, t2;
double a[100005];
double d1, d2, d3, d4;

void build(int node)
{
	if(node>=max/2)
		return;

	build(node*2);
	build(node*2 +1);

	tree[node] = tree[node*2] + tree[node*2 +1];
}

void update(int node, int a, int b, int i, int j, double mul, double ad)
{
	if(lazy_add[node] != 0.0)
	{
		tree[node] *= lazy_mult[node];
		tree[node] += lazy_add[node] * (b-a+1);

		if(node < max/2)
		{
			lazy_add[node*2] = lazy_add[node*2]*lazy_mult[node] + lazy_add[node];
			lazy_mult[node*2] *= lazy_mult[node];
			
			lazy_add[node*2 +1] = lazy_add[node*2 +1]*lazy_mult[node] + lazy_add[node];
			lazy_mult[node*2 +1] *= lazy_mult[node];
		}

		lazy_add[node] = 0.0;
		lazy_mult[node] = 1.0;
	}
	
	if(j<a || b<i || a>b)
		return;

	if(i<=a && j>=b)
	{
		tree[node] *= mul;
		tree[node] += ad * (b-a+1);

		if(node<max/2)
		{
			lazy_mult[node*2] *= mul;
			lazy_add[node*2] = lazy_add[node*2]*mul + ad;

			lazy_mult[node*2 +1] *= mul;
			lazy_add[node*2 +1] = lazy_add[node*2 +1]*mul + ad;
		}
		return;
	}

	update(node*2, a, (a+b)/2, i, j, mul, ad);
	update(node*2 +1, (a+b)/2 +1, b, i, j, mul, ad);

	tree[node] = tree[node*2] + tree[node*2 +1];
}

double query(int node, int a, int b, int i, int j)
{
	if(j<a || b<i || a>b)
		return 0.0;

	if(lazy_add[node] != 0.0)
	{
		tree[node] *= lazy_mult[node];
		tree[node] += lazy_add[node] * (b-a+1);

		if(node < max/2)
		{
			lazy_add[node*2] = lazy_add[node*2]*lazy_mult[node] + lazy_add[node];
			lazy_mult[node*2] *= lazy_mult[node];
			
			lazy_add[node*2 +1] = lazy_add[node*2 +1]*lazy_mult[node] + lazy_add[node];
			lazy_mult[node*2 +1] *= lazy_mult[node];
		}

		lazy_add[node] = 0.0;
		lazy_mult[node] = 1.0;
	}

	if(i<=a && j>=b)
		return tree[node];

	double a1 = query(node*2, a, (a+b)/2, i, j);
	double a2 = query(node*2 +1, (a+b)/2 +1, b, i, j);
	return a1 + a2;
}

void init(int size_of_input_array)
{
	int n = size_of_input_array;
	f(i, n)
		cin>>tree[i+max/2];

	F(i, n, max/2, 1)
		tree[i+max/2] = 0.0;

	f(i, max)
	{
		lazy_mult[i] = 1.0;
		lazy_add[i] = 0.0;
	}

	build(1);
}

int main()
{
	read2(n, q);
	init(n);

	f(z, q)
	{
		read(t);
		if(t==1)
		{
			read2(l1, r1);
			read2(l2, r2);

			l1--, r1--;
			l2--, r2--;
			
			t1 = r1-l1+1;
			t2 = r2-l2+1;

			d1 = query(1, max/2, max-1, max/2 +l1, max/2 +r1);
			d2 = query(1, max/2, max-1, max/2 +l2, max/2 +r2);

			update(1, max/2, max-1, max/2 +l1, max/2+r1, (t1-1)*1.0/t1, d2/t1/t2);
			update(1, max/2, max-1, max/2 +l2, max/2+r2, (t2-1)*1.0/t2, d1/t1/t2);
		}
		else
		{
			read2(l, r);
			l--;
			r--;

			d1 = query(1, max/2, max-1, max/2 +l, max/2 +r);
			printf("%.9lf\n", d1);
		}
	}
}