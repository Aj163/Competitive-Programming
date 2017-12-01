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
 
int t, n, m, x, y, c, flag;
int val[1000009], vis[1000009];
vector< pii > v[1000009];
 
void dfs(int s)
{
	if(vis[s])
		return;
	vis[s]=1;
 
	f(i, v[s].size())
	{
		int a = v[s][i].first;
		int b = v[s][i].second;
 
		if(val[a]==-1)
		{
			if(b==1)
				val[a] = 1-val[s];
			else
				val[a] = val[s];
 
			dfs(a);
		}
		else if(abs(val[s] - val[a]) != b)
		{
			flag=0;
			break;
		}
	}
}
 
int main()
{
	read(t);
	f(z, t)
	{
		read2(n, m);
		f(i, n+1)
			v[i].clear();
 
		f(i, n+1)
		{
			vis[i]=0;
			val[i]=-1;
		}
 
		f(i, m)
		{
			read3(x, y, c);
			v[x].pb(mp(y, c));
			v[y].pb(mp(x, c));
		}
 
		flag=1;
		F(i, 1, n+1, 1)
			if(vis[i]==0)
			{
				val[i]=0;
				dfs(i);
			}
 
		if(flag)
			printf("yes\n");
		else
			printf("no\n");
	}
}  