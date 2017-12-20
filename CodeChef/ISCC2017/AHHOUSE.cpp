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
 
bool chk(int x, int y, int n, int m)
{
	if(x<0 || y<0 || x>=n || y>=m)
		return false;
	return true;
}
 
int main()
{
	ios::sync_with_stdio(false);
	int t, n, m, pf[10][10], pt[10][10], vis[10][10], a, b, c, d;
	multiset< pair< pii, pii > > q;
	pair< pii, pii > p;
	pii dis[10][10];
 
	cin>>t;
	f(z, t)
	{
		cin>>n>>m;
		f(i, n)
			f(j, m)
				cin>>pf[i][j];
		f(i, n)
			f(j, m)
				cin>>pt[i][j];
 
		f(i, n)
			f(j, m)
			{
				dis[i][j]=mp(1e9, 1e9);
				vis[i][j]=0;
			}
 
		q.insert(mp(mp(0, 0), mp(0, 0)));
		dis[0][0] = mp(0, 0);
		while(!q.empty())
		{
			p = *q.begin();
			q.erase(q.begin());
 
			c = p.second.first;
			d = p.second.second;
			//cout<<"@@#$#@"<<c<<" "<<d<<" "<<q.size()<<endl;
 
			if(vis[c][d])
				continue;
			vis[c][d]=1;
 
			if(chk(c+1, d, n, m))
			{
				if(dis[c+1][d].first > dis[c][d].first + pf[c][d])
				{
					dis[c+1][d].first = dis[c][d].first + pf[c][d];
					dis[c+1][d].second = dis[c][d].second + pt[c][d];
					q.insert(mp(dis[c+1][d], mp(c+1, d)));
				}
				else if(dis[c+1][d].first == dis[c][d].first + pf[c][d])
				{
					dis[c+1][d].second = min(dis[c+1][d].second, dis[c][d].second + pt[c][d]);
					q.insert(mp(dis[c+1][d], mp(c+1, d)));
				}
			}
			if(chk(c-1, d, n, m))
			{
				if(dis[c-1][d].first > dis[c][d].first + pf[c][d])
				{
					dis[c-1][d].first = dis[c][d].first + pf[c][d];
					dis[c-1][d].second = dis[c][d].second + pt[c][d];
					q.insert(mp(dis[c-1][d], mp(c-1, d)));
				}
				else if(dis[c-1][d].first == dis[c][d].first + pf[c][d])
				{
					dis[c-1][d].second = min(dis[c-1][d].second, dis[c][d].second + pt[c][d]);
					q.insert(mp(dis[c-1][d], mp(c-1, d)));
				}
			}
			if(chk(c, d+1, n, m))
			{
				if(dis[c][d+1].first > dis[c][d].first + pf[c][d])
				{
					dis[c][d+1].first = dis[c][d].first + pf[c][d];
					dis[c][d+1].second = dis[c][d].second + pt[c][d];
					q.insert(mp(dis[c][d+1], mp(c, d+1)));
				}
				else if(dis[c][d+1].first == dis[c][d].first + pf[c][d])
				{
					dis[c][d+1].second = min(dis[c][d+1].second, dis[c][d].second + pt[c][d]);
					q.insert(mp(dis[c][d+1], mp(c, d+1)));
				}
			}
			if(chk(c, d-1, n, m))
			{
				if(dis[c][d-1].first > dis[c][d].first + pf[c][d])
				{
					dis[c][d-1].first = dis[c][d].first + pf[c][d];
					dis[c][d-1].second = dis[c][d].second + pt[c][d];
					q.insert(mp(dis[c][d-1], mp(c, d-1)));
				}
				else if(dis[c][d-1].first == dis[c][d].first + pf[c][d])
				{
					dis[c][d-1].second = min(dis[c][d-1].second, dis[c][d].second + pt[c][d]);
					q.insert(mp(dis[c][d-1], mp(c, d-1)));
				}
			}
		}
 
		cout<<dis[n-1][m-1].first + pf[n-1][m-1]<<" "<<dis[n-1][m-1].second + pt[n-1][m-1]<<endl;
	}
} 