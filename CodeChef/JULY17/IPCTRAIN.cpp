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
 
int main()
{
	ios::sync_with_stdio(false);
	int t, n, m, d, ti, si, q;
	ll ans;
	pair< int, pii > p[100000];
	pii x;
	set< pii > s;
	set< pii >::iterator it;
 
	cin>>t;
	f(z, t)
	{
		cin>>n>>m;
		s.clear();
		f(i, n)
		{
			cin>>d>>ti>>si;
			p[i]=mp(d, mp(ti, si));
		}
 
		sort(p, p+n);
		q=0;
 
		F(i, 1, m+1, 1)
		{
			while(q<n)
			{
				if(p[q].first<=i)
				{
					x=mp(p[q].second.second, p[q].second.first);
					while(s.find(x)!=s.end())
					{
						s.erase(s.find(x));
						x.second*=2;
					}
					s.insert(x);
				}
				else
					break;
				q++;
			}
 
			if(s.empty())
				continue;
			else
			{
				it=s.end();
				it--;
				x=*it;
 
				s.erase(it);
				x.second--;
 
				//cout<<i<<" -> "<<s.size()<<", "<<x.second<<endl;
 
				if(x.second>0)
				{
					while(s.find(x)!=s.end())
					{
						s.erase(s.find(x));
						x.second*=2;
					}
					s.insert(x);
				}
			}
		}
 
		ans=0;
		while(!s.empty())
		{
			x=*s.begin();
			s.erase(s.begin());
			ans+=x.first*1ll*x.second;
		}
		cout<<ans<<endl;
	}
}  