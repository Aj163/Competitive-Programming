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
	int t, flag, l, vis[26], d[26];
	char a[1001], b[1001];
	vi v[26];
 
	cin>>t;
	f(z, t)
	{
		f(i, 26)
		{
			v[i].clear();
			vis[i]=0;
			d[i]=0;
		}
 
		cin>>a>>b;
		if(!strcmp(a, b))
		{
			cout<<"YES\n";
			continue;
		}
		l = strlen(a);
 
		f(i, l)
			v[a[i]-'a'].pb(i);
		
		flag=1;
		f(i, 26)
			if(!v[i].size())
			{
				flag=0;
				break;
			}
 
		if(flag)
		{
			cout<<"NO\n";
			continue;
		}
		flag=1;
 
		for(int i=0; i<26 && flag; i++)
		{
			if(v[i].size()==1)
			{
				if(vis[a[v[i][0]] - 'a']==0)
					vis[a[v[i][0]] - 'a']=1;
				else
				{
					flag=0;
					//cout<<"#";
					break;
				}
 
				if(d[b[v[i][0]] - 'a']==0)
					d[b[v[i][0]] - 'a']=1;
				else
				{
					flag=0;
					//cout<<"#";
					break;
				}
			}
			else if(v[i].size()>1)
			{
				if(vis[a[v[i][0]] - 'a']==0)
					vis[a[v[i][0]] - 'a']=1;
				else
				{
					flag=0;
					//cout<<"#";
					break;
				}
 
				if(d[b[v[i][0]] - 'a']==0)
					d[b[v[i][0]] - 'a']=1;
				else
				{
					flag=0;
					//cout<<"#";
					break;
				}
 
				F(j, 1, v[i].size(), 1)
				{
					if(b[v[i][j]]!=b[v[i][0]])
					{
						flag=0;
						//cout<<"#";
						break;
					}
				}
			}
		}
 
		if(!flag)
		{
			cout<<"NO\n";
			continue;
		}
		cout<<"YES\n";
	}
} 