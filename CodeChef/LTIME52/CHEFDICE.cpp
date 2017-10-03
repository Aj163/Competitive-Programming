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
 
#define M 1000000007
#define pb push_back
#define mp make_pair
 
#define pii pair<int, int>
#define vi vector<int>
#define ll long long
 
using namespace std;
 
int main()
{
	int t, n, a[509], flag, p[10][10], ans[10], used[10];
	vi v;
 
	read(t);
	f(z, t)
	{
		read(n);
		f(i, n)
		{
			read(a[i]);
			a[i]--;
		}
 
		memset(p, 0, sizeof(p));
		memset(ans, 0, sizeof(ans));
		memset(used, 0, sizeof(used));
		v.clear();
		f(i, 6)
			v.pb(i);
		flag=1;
 
		if(n==1)
		{
			printf("6 5 4 3 2 1\n");
			continue;
		}
 
		f(i, n)
		{
			if(i==0)
				p[a[i]][a[i+1]]=1;
			else if(i==n-1)
				p[a[i]][a[i-1]]=1;
			else
			{
				p[a[i]][a[i+1]]=1;
				p[a[i]][a[i-1]]=1;
			}
		}
 
		f(i, 6)
		{
			if(p[i][i]==1)
			{
				flag=0;
				break;
			}
 
			int ctr=0;
			f(j, 6)
				ctr+=p[i][j];
 
			if(ctr==5)
			{
				flag=0;
				break;
			}
		}
 
		if(!flag)
		{
			printf("-1\n");
			continue;
		}
 
		do
		{
			flag=1;
			f(i, 6)
				if(v[i]==i || p[i][v[i]]==1 || v[v[i]] != i)
				{
					flag=0;
					break;
				}
 
			if(flag==0)
				continue;
			else
			{
				f(i, 6)
					printf("%d ", v[i]+1);
				printf("\n");
				break;
			}
			flag=0;
		}while(next_permutation(v.begin(), v.end()));
 
		if(!flag)
		{
			printf("-1\n");
			continue;
		}
	}
} 