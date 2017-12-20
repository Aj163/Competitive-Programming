#include <bits/stdc++.h>
#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)
#define M 1000000007
#define PII pair<int, int>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t, n, z, l, id[2501], s, x, ans;
	vector<int> v[2500];

	cin>>t;
	f(i, t)
	{
		ans=0;
		cin>>n>>z;
		f(j, n)
		{
			v[j].clear();
			cin>>l;
			f(k, l)
			{
				cin>>x;
				v[j].push_back(x);
			}
		}
		f(j, n)
			F(k, j+1, n, 1)
			{
				if(v[j].size()+v[k].size()<z)
					continue;
				s=0;
				f(l, z+1)
					id[l]=0;
				f(l, v[j].size())
					if(v[j][l]<=z && id[v[j][l]]==0)
					{
						id[v[j][l]]=1;
						s++;
					}
				f(l, v[k].size())
					if(v[k][l]<=z && id[v[k][l]]==0)
					{
						id[v[k][l]]=1;
						s++;
					}
				if(s==z)
					ans++;
			}
		cout<<ans<<endl;
	}
}