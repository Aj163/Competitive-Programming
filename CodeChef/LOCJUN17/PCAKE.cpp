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
	int t, n, a[100000], k, p[1001], pos, id[1001];
	ll ans;
	vi v[1001];
	set<int> s;

	f(i, 1001)
	{
		p[i]=1;
		id[i]=0;
	}

	p[0]=0;
	p[1]=0;

	F(i, 2, 321, 1)
		if(p[i]==1)
		{
			F(j, 2*i, 1001, i)
				p[j]=0;
		}

	F(i, 2, 1001, 1)
	{
		k=i;
		F(j, 2, 1001, 1)
		{
			if(k==1)
				break;
			if(p[j]==1 && k%(j*j)==0)
				id[i]=1;
			else if(p[j]==1 && k%j==0)
			{
				v[i].pb(j);
				k/=j;
			}
		}
	}

	cin>>t;
	f(z, t)
	{
		cin>>n;
		f(i, n)
			cin>>a[i];

		ans=0;
		s.clear();
		pos=0;

		f(i, n)
		{
			if(id[a[i]]==1)
				continue;

			if(pos<i)
				pos=i;

			while(pos<n)
			{
				if(id[a[pos]]==1)
					break;

				int j;
				for(j=0; j<v[a[pos]].size(); j++)
				{
					if(s.find(v[a[pos]][j])==s.end())
						s.insert(v[a[pos]][j]);
					else
						break;
				}
				if(j!=v[a[pos]].size())
				{
					f(y, j)
						s.erase(v[a[pos]][y]);
					break;
				}
				pos++;
			}

			ans+=pos-i;
			//cout<<i<<" "<<pos<<endl;
			f(j, v[a[i]].size())
				s.erase(v[a[i]][j]);
		}
		cout<<ans<<endl;
	}
}