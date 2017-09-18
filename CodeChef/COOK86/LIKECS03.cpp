#include <bits/stdc++.h>
 
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
	int t, n, a, k, c;
	set<int> s;
 
	read(t);
	f(z, t)
	{
		read2(n, k);
		s.clear();
		
		f(i, n)
		{
			read(a);
			s.insert(a);
		}
 
		c=0;
		f(i, k)
		{
			if(s.find((1<<i))==s.end())
				c++;
		}
		printf("%d\n", c);
	}
} 