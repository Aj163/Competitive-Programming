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
	int t, n, m, ms[1000], os[1000], mjo[1000], qual[1000][1000], noj, hire[1000], noh;
	ll ts;
	char y;
	set< pii > s;
	set< pii >::iterator it;
 
	cin>>t;
	f(z, t)
	{
		cin>>n>>m;
 
		f(i, n)
			cin>>ms[i];
 
		f(i, m)
		{
			hire[i] = 1;
			cin>>os[i]>>mjo[i];
		}
 
		f(i, n)
			f(j, m)
			{
				cin>>y;
				qual[i][j] = y-'0';
			}
 
		noj = 0;
		ts = 0;
		noh = 0;
 
		f(i, n)
		{
			s.clear();
			f(j, m)
				if(qual[i][j] && mjo[j]>0)
					s.insert(mp(os[j], j));
 
			if(s.begin() == s.end())
				continue;
 
			it = s.end();
			it--;
 
			if((*it).first > ms[i])
			{
				noj++;
				ts += os[(*it).second];
				hire[(*it).second] = 0;
				mjo[(*it).second]--;
			}
		}
 
		f(i, m)
			noh += hire[i];
 
		cout<<noj<<" "<<ts<<" "<<noh<<endl;
	}
} 