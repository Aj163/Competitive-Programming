#include <bits/stdc++.h>
#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)
#define M 1000000007
#define PII pair<int, int>
#define VI vector<int>
#define VIT vector<int>::iterator
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int t, n, a[1000000], b[1000000], pos;
	long long ans, sum;
	set<int> s;

	cin>>t;
	f(i, t)
	{
		cin>>n;
		f(j, n)
			cin>>a[j];
		f(j, n)
			cin>>b[j];

		ans=0;
		sum=0;
		pos=0;
		s.clear();

		f(j, n)
		{
			if(s.find(a[j])==s.end())
			{
				s.insert(a[j]);
				sum+=b[j];
				ans=max(ans, sum);
			}
			else
			{
				while(a[pos]!=a[j])
				{
					sum-=b[pos];
					s.erase(s.find(a[pos]));
					pos++;
				}
				sum-=b[pos];
				s.erase(s.find(a[pos]));
				pos++;

				s.insert(a[j]);
				sum+=b[j];
				ans=max(ans, sum);
			}
		}
		cout<<ans<<endl;
	}
}

