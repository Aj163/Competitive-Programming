#include <bits/stdc++.h>
//#include <unordered_map>

#define f(i, num) for(int i=0; i<num; i++)
#define F(i, lower, upper, step) for(int i=lower; i<upper; i+=step)
#define F_(i, upper, lower, step) for(int i=upper; i>lower; i-=step)

#define read(num) scanf("%d", &num);
#define read2(numa, num2) scanf("%d%d", &numa, &num2);
#define read3(numa, num2, num3) scanf("%d%d%d", &numa, &num2, &num3);
#define reads(str) scanf("%s", str);
#define readc(ch) scanf("%c", ch);
#define N 200009
#define M 1000000007
#define pb push_back
#define mp make_pair

#define pii pair<int, int>
#define vi vector<int>
#define ll long long

using namespace std;

int a[N],vis[N],used[N];
set<int> s1,s2;
vector<int> final;

int main()
{
	int i,j,t1,t2,t3,t4,n,ans=0;
	scanf("%d",&n);
	f(i, n)
	{
		scanf("%d",&a[i]);
		vis[a[i]]++;
		s1.insert(a[i]);
	}
	for(i=1;i<=n;i++)
	{

		if(s1.find(i)==s1.end())
		{
			s2.insert(i);
		}
	}
	f(i, n)
	{
		if(used[a[i]]==1)
		{
			set<int>::iterator it=s2.begin();
			final.push_back(*it);
			s2.erase(*it);
			ans++;
			continue ;
		}
		if(vis[a[i]]>1)
		{
			set<int>::iterator it=s2.begin();
			if(*it<a[i])
			{
				vis[a[i]]--;
				ans++;
				final.push_back(*it);
				s2.erase(*it);
			}
			else
			{

				used[a[i]]=1;
				final.push_back(a[i]);
			}
		}
		else
		{
			final.push_back(a[i]);
			used[a[i]]=1;
		}
	}

	printf("%d\n",ans);
	for(auto it2 : final){
		printf("%d ",it2);
	}
	printf("\n");

}