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

int main()
{
	ios::sync_with_stdio(false);
	int n, q, x[3], cnt;
	string str;

	cin>>n;
	f(i, n)
		cin>>tree[i+max/2];

	F(i, n, max/2, 1)
		tree[i+max/2] = inf;

	f(i, max)
		lazy[i] = 0;

	build(1);

	cin>>q;
	getline(cin, str);
	f(z, q)
	{
	    cnt=0;
		getline(cin, str);
        ll sz= str.size();
        for(ll i=0; i<sz; i++)
        {
            bool flg= 0;
            ll sum= 0;
            if(str[i]>=48&&str[i]<=57)
            {
                if(i>0&&str[i-1]=='-')
                    flg= 1;
                while(str[i]>=48&&str[i]<=57)
                {
                    sum= sum*10+(str[i]-48);
                    i++;
                }
                if(flg)
                    sum*= -1;
                x[cnt] = sum;
                cnt++;
            }
        }
        
        
        
		if(cnt==3)
		{
			if(x[0]<=x[1])
				update(1, max/2, max-1, x[0]+max/2, x[1]+max/2, x[2]);
			else
			{
				update(1, max/2, max-1, x[0]+max/2, max-1, x[2]);
				update(1, max/2, max-1, max/2, x[1]+max/2, x[2]);
			}
		}
		else if(cnt==2)
		{
			if(x[0]<=x[1])
				cout<<query(1, max/2, max-1, x[0]+max/2, x[1]+max/2)<<endl;
			else
			{
				ll a1 = query(1, max/2, max-1, x[0]+max/2, max-1);
				ll a2 = query(1, max/2, max-1, max/2, x[1]+max/2);
				cout<<min(a1, a2)<<endl;
			}
		}
		
		/*f(i, max)
            cout<<tree[i]<<" ";
        cout<<endl;*/
		
	}
}